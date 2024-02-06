# Domótica con Node-RED

Demo de implementación de panel domótico con Node-RED para proyectos de dómotica de bajo costo. 

[Node-RED](https://nodered.org/) es una herramienta de desarrollo basada en flujo para programación visual desarrollada originalmente por IBM para conectar dispositivos de hardware, API y servicios en línea como parte de la Internet de las cosas. Proporciona un editor de flujo basado en navegador web, que se puede utilizar para crear funciones de JavaScript. 

![](./docs/images/Node-RED%20Editor.png)
*Node-RED Editor*.

Los elementos de las aplicaciones se pueden guardar o compartir para su reutilización. El tiempo de ejecución se basa en Node.js. Los flujos creados en Node-RED se almacenan mediante JSON. Desde la versión 0.14, los nodos MQTT pueden realizar conexiones TLS correctamente configuradas. En 2016, IBM contribuyó con Node-RED como un proyecto de OpenJS Foundation de código abierto. [Wikipedia](https://en.wikipedia.org/wiki/Node-RED).

## Arquitectura del sistema

El sistema está basado en los siguientes componentes:

- Servidor: broker MQTT Mosquitto (cloud).
- Cliente: dashboard sobre Node-RED.
- Cliente: hardware con sensores de temperatura y humedad ambiente, y actuador.

![](./docs/images/arquitectura.png)
*Arquitectura del sistema*.

## Broker MQTT

El servidor puede estar instalado en una [Raspberry Pi](https://es.wikipedia.org/wiki/Raspberry_Pi) o bien es posible utilizar algún broker público. En este caso utilizamos [test.mosquitto.org](https://test.mosquitto.org/) que alberga un servidor/broker MQTT [Eclipse Mosquitto](https://mosquitto.org/) públicamente. 

El servidor escucha en los siguientes puertos:

- `1883` MQTT, unencrypted, unauthenticated
- `1884` MQTT, unencrypted, authenticated
- `8883` MQTT, encrypted, unauthenticated
- `8884` MQTT, encrypted, client certificate required
- `8885` MQTT, encrypted, authenticated
- `8886` MQTT, encrypted, unauthenticated
- `8887` MQTT, encrypted, server certificate deliberately expired
- `8080` MQTT over WebSockets, unencrypted, unauthenticated
- `8081` MQTT over WebSockets, encrypted, unauthenticated
- `8090` MQTT over WebSockets, unencrypted, authenticated
- `8091` MQTT over WebSockets, encrypted, authenticated

Para realizar pruebas es posible utilizar algún cliente *desktop* como [MQTT Explorer](http://mqtt-explorer.com/).

![](./docs/images/MQTT%20Explorer.png)
*MQTT Explorer ejecutándose sobre Ubuntu 22.04*.

## Implementando un dashboard con Node-RED

Node-RED permite gestionar la recepción y envio de información a través de un broker MQTT, para poder comunicarse con los diferentes clientes del sistema (apps móviles, hardware, etc.). Además permite diseñar y poner en línea un completo *dashboard* (o panel de control) con la posibilidad de insertar diferentes widgets tanto para mostrar como para enviar datos.

![](./docs/images/dashboard_02.png)
*Dashboard UI*.

En este proyecto se utilizaron las siguientes dependencias:

- [node-red-dashboard](https://flows.nodered.org/node/node-red-dashboard)
- [node-red-contrib-ui-media](https://flows.nodered.org/node/node-red-contrib-ui-media)

## Hardware

El hardware para este demo está basado en una placa NodeMCU (SoC ESP8266) aunque se puede utilizar sin problemas con placas basadas en el SoC ESP32. El diagrama esquemático de la versión con el SoC ESP8266 es el siguiente:

![](./hardware/schematic.png)
*Diagrama esquemático*.

Hay dos versiones disponible del firmware del SoC: una implementación en C++ mediante la API de Arduino, y otra con MicroPython.

## Firmware Arduino API

La primera versión del firmware, en C++, se encuentra en el directorio `./hardware/fw_arduino`. Además hay una versión funcional en línea sobre el SoC ESP32, disponible en [Wokwi](https://wokwi.com/projects/378045103778705409).

Para compilar, el proyecto necesita las siguientes dependencias:

- [PubSubClient](https://github.com/knolleary/pubsubclient)
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

## Firmware MicroPython

La segunda versión del firmware, en MicroPython, se encuentra en el directorio `./hardware/fw_micropython`. Además hay una versión funcional en línea sobre el SoC ESP32, disponible en [Wokwi](https://wokwi.com/projects/388923768636934145).

Para escribir código en MicroPython y poder cargar tanto el firmware (el interprete Python) como los scripts en la memoria del SoC, es posible utilizar Thonny.

Thonny es un entorno de desarrollo integrado gratuito y de código abierto para Python diseñado para principiantes. Fue creado por Aivar Annamaa, un programador estonio. Admite diferentes formas de recorrer el código paso a paso, evaluación de expresiones paso a paso, visualización detallada de la pila de llamadas y un modo para explicar los conceptos de referencias y montón.[Wikipedia](https://en.wikipedia.org/wiki/Thonny).

![](./docs/images/Thonny.png)
*Thonny IDE*.

Para funcionar, es necesaria la siguiente dependencia:

- [micropython-umqtt.robust](https://pypi.org/project/micropython-umqtt.robust/)

**umqtt** es un cliente MQTT sencillo para MicroPython, que consta de dos submódulos: *umqtt.simple* y *umqtt.robust*. umqtt.robust está construido sobre umqtt.simple y agrega funciones de reconexión automática para lidiar con algunos errores de red.

## Recursos

- [ESP32 Pinout Reference: Which GPIO pins should you use?](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)
- [ESP8266 Pinout Reference: Which GPIO pins should you use?](https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/)
- [MicroPython](https://github.com/micropython/micropython)
- [Thonny Python IDE for beginners](https://github.com/thonny/thonny/)

## Licencia

Este trabajo está protegido por la **Licencia MIT**. Puedes acceder a la versión original de la licencia (en inglés) a través del archivo [LICENSE](./LICENSE) o en línea en [The MIT License (MIT)](https://mit-license.org/). También proporcionamos una traducción no oficial desde [Wikipedia](https://es.m.wikipedia.org/wiki/Licencia_MIT#La_licencia):

Copyright (c) 2024 Lucas Martín Treser

Por la presente se concede permiso, libre de cargos, a cualquier persona que obtenga una copia de este software y de los archivos de documentación asociados (el "Software"), a utilizar el Software sin restricción, incluyendo sin limitación los derechos a usar, copiar, modificar, fusionar, publicar, distribuir, sublicenciar, y/o vender copias del Software, y a permitir a las personas a las que se les proporcione el Software a hacer lo mismo, sujeto a las siguientes condiciones:

El aviso de copyright anterior y este aviso de permiso se incluirán en todas las copias o partes sustanciales del Software.

EL SOFTWARE SE PROPORCIONA "COMO ESTÁ", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A GARANTÍAS DE COMERCIALIZACIÓN, IDONEIDAD PARA UN PROPÓSITO PARTICULAR E INCUMPLIMIENTO. EN NINGÚN CASO LOS AUTORES O PROPIETARIOS DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE NINGUNA RECLAMACIÓN, DAÑOS U OTRAS RESPONSABILIDADES, YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O CUALQUIER OTRO MOTIVO, DERIVADAS DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O SU USO U OTRO TIPO DE ACCIONES EN EL SOFTWARE.
