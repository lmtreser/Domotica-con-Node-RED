/*
  * Panel domótica con Node-RED
  * 
  * Demo de implementación de panel domótico con Node-RED para proyectos 
  * de dómotica de bajo costo. 
  * 
  * created 01 Sep 2022
  * by Lucas Martin Treser
  * 
  * modified 22 Mar 2023
  * modified 01 Oct 2023
  * modified 05 Feb 2024
  * by Lucas Martin Treser      
  * 
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "credenciales.h"
#include "DHT.h"

#define DHTPIN D2
#define DHTTYPE DHT11

WiFiClient espClient;
PubSubClient client(espClient);

//Constantes y variables
const int MSG_BUFFER_SIZE = 20;
const int LED_ROJO = D1;
const char actuador[] = "true";
char mensaje[MSG_BUFFER_SIZE];
int flag;

//Función callback mqtt
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido desde el topic [");
  Serial.print(topic);
  Serial.print("]: ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    if ((char)payload[i] == actuador[i]) {
      flag++;
    }
    if (flag == 4) {
      flag = 0;
      digitalWrite(LED_ROJO, HIGH);
    }
    else {
      digitalWrite(LED_ROJO, LOW);
    }
  }
  Serial.println();
}

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  dht.begin();
  Serial.begin(9600);

  // -- Conexión a la red WiFi --
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Conectando a:\t");
  Serial.println(ssid);

  // Esperar a que la placa se conecte
  bool led = false;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
    digitalWrite(LED_BUILTIN, led);
    led = !led;
  }

  // Si la conexión es exitosa muestra la IP asignada
  Serial.println();
  Serial.print("Conectado a:\t");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, HIGH);

  // -- Conexión al broker MQTT --
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.print("Tratando de conectar al broker MQTT...");
    if (client.connect(mqtt_id)) {
      Serial.println("conectado");
    } else {
      Serial.print("fallo, error=");
      Serial.print(client.state());
      Serial.println(" intentando nuevamente en 2 segundos");
      delay(2000);
    }
  }

  // Subscribirse a un topic
  client.subscribe(mqtt_topic_3);
}

void loop() {

  client.loop();

  //Obtener datos desde el sensor
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" | Humedad: ");
  Serial.println(humedad);

  //Publicar la temperatura
  snprintf(mensaje, MSG_BUFFER_SIZE, "%.2f", temperatura);
  client.publish(mqtt_topic_1, mensaje);

  //Publicar la humedad
  snprintf(mensaje, MSG_BUFFER_SIZE, "%.2f", humedad);
  client.publish(mqtt_topic_2, mensaje);

  delay(2000);
}
