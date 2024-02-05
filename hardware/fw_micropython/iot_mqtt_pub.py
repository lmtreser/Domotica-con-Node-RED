# Ejemplo Introducción al IoT
# /entradas/switch - Opera a distancia un LED
# /entradas/sensor/temperatura - Envia la temperatura periodicamente
# /entradas/sensor/humedad - Enviar la humedad periodicamente

import network
from dht import DHT11
from time import sleep_ms
from machine import Pin, Timer
from umqtt.robust import MQTTClient

# ----- Definicion de dispositivos
dht = DHT11(Pin(4))    # GPIO4 = D2
led = Pin(5, Pin.OUT)  # GPIO5 = D1

# ----- Lectura de humedad y temperatura
def temperatura(timer):
    dht.measure()
    temp = dht.temperature()
    hum = dht.humidity()
    cliente.publish("/entradas/sensor/temperatura", str(temp))
    cliente.publish("/entradas/sensor/humedad", str(hum))
    print(f"Temperatura: {temp} °C")
    print(f"Humedad: {hum} %RH\n")

# ----- Funcion callback MQTT
def callback(topic, msg):
    
    # Recibo y decodifico los datos
    mensaje = msg.decode()
    topico = topic.decode()
    
    # LED
    if (topico == "/entradas/switch"):
        if (mensaje == "true"):
            led.value(1)
        elif (mensaje == "false"):
            led.value(0)
    print(mensaje)

# Conexión a Internet
wlan = network.WLAN(network.STA_IF)
if not wlan.active():
    wlan.active(True)

if not wlan.isconnected():
    wlan.connect("ssid","password")
    print("Conectando...")
    while not wlan.isconnected():
        sleep_ms(1000)

config = wlan.ifconfig()
print(f"Conectado con ip {config[0]}")

# Conexión al broker MQTT
cliente = MQTTClient("esp32", "192.168.1.33", port=1883)
print("Conectando a servidor MQTT...")
cliente.set_callback(callback)
cliente.connect()
cliente.subscribe("/entradas/switch")
print("Conectado")

# ----- Inicia el Timer0
tim = Timer(0)
tim.init(period=5000, mode=Timer.PERIODIC, callback=temperatura)

while True:
    cliente.check_msg()

cliente.disconnect()
