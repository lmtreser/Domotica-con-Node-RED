# Panel domótica con Node-RED

Demo de implementación de panel domótico con Node-RED para proyectos de dómotica de bajo costo. 

[Node-RED](https://nodered.org/) es una herramienta de desarrollo basada en flujo para programación visual desarrollada originalmente por IBM para conectar dispositivos de hardware, API y servicios en línea como parte de la Internet de las cosas. Proporciona un editor de flujo basado en navegador web, que se puede utilizar para crear funciones de JavaScript. Los elementos de las aplicaciones se pueden guardar o compartir para su reutilización. El tiempo de ejecución se basa en Node.js. Los flujos creados en Node-RED se almacenan mediante JSON. Desde la versión 0.14, los nodos MQTT pueden realizar conexiones TLS correctamente configuradas. En 2016, IBM contribuyó con Node-RED como un proyecto de OpenJS Foundation de código abierto. [Wikipedia](https://en.wikipedia.org/wiki/Node-RED).

## Hardware

El hardware para este demo está basado en una placa NodeMCU (SoC ESP8266) aunque se puede utilizar sin problemas con placas basadas en el SoC ESP32.

## Implementación con Node-RED



## Firmware con Arduino API



## Firmware con MicroPython

Metadata-Version: 1.0
Name: micropython-umqtt.robust
Version: 1.0
Summary: Lightweight MQTT client for MicroPython ("robust" version).
Home-page: https://github.com/micropython/micropython/issues/405
Author: MicroPython Developers
Author-email: micro-python@googlegroups.com
License: MIT
Description: umqtt.robust
        ============

        umqtt is a simple MQTT client for MicroPython. (Note that it uses some
        MicroPython shortcuts and doesn't work with CPython). It consists of
        two submodules: umqtt.simple and umqtt.robust. umqtt.robust is built
        on top of umqtt.simple and adds auto-reconnect facilities for some of
        networking errors.

umqtt.robust
umqtt is a simple MQTT client for MicroPython. (Note that it uses some
MicroPython shortcuts and doesn't work with CPython). It consists of
two submodules: umqtt.simple and umqtt.robust. umqtt.robust is built
on top of umqtt.simple and adds auto-reconnect facilities for some of
networking errors.

## Licencia

Este trabajo está protegido por la **Licencia MIT**. Puedes acceder a la versión original de la licencia (en inglés) a través del archivo [LICENSE](./LICENSE) o en línea en [The MIT License (MIT)](https://mit-license.org/). También proporcionamos una traducción no oficial desde [Wikipedia](https://es.m.wikipedia.org/wiki/Licencia_MIT#La_licencia):

Copyright (c) 2024 Lucas Martín Treser

Por la presente se concede permiso, libre de cargos, a cualquier persona que obtenga una copia de este software y de los archivos de documentación asociados (el "Software"), a utilizar el Software sin restricción, incluyendo sin limitación los derechos a usar, copiar, modificar, fusionar, publicar, distribuir, sublicenciar, y/o vender copias del Software, y a permitir a las personas a las que se les proporcione el Software a hacer lo mismo, sujeto a las siguientes condiciones:

El aviso de copyright anterior y este aviso de permiso se incluirán en todas las copias o partes sustanciales del Software.

EL SOFTWARE SE PROPORCIONA "COMO ESTÁ", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A GARANTÍAS DE COMERCIALIZACIÓN, IDONEIDAD PARA UN PROPÓSITO PARTICULAR E INCUMPLIMIENTO. EN NINGÚN CASO LOS AUTORES O PROPIETARIOS DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE NINGUNA RECLAMACIÓN, DAÑOS U OTRAS RESPONSABILIDADES, YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O CUALQUIER OTRO MOTIVO, DERIVADAS DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O SU USO U OTRO TIPO DE ACCIONES EN EL SOFTWARE.
