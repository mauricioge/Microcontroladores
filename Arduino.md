# ARDUINO: Preparando el entorno de trabajo
Pasos para preparar el Arduino IDE para ejecutar los ejemplos del seminario: **IoT: Comunicando Microcontroladores con otras Tecnologías.**

## PLACAS:
Vamos a trabajar con las siguientes placas: Arduino UNO R3, Arduino MKR1000, ESP-01, NodeMCU V1 y ESP WROOM 32.  
Los controladores que permiten a Arduino IDE compilar los sketch segun los requerimientos del hardware de las placas Arduino se instalan junto con el Arduino IDE. En el caso de las placas ESP-01, NodeMCU V1 y ESP WROOM 32, nosotros tendremos que instalar los controladores. Lo mismo ocurre con varias de las librerias que vamos a usar.

## **SOFTWARE:** 💾
- Para instalar los controladores de las placas ESP-01, NodeMCU V1 y ESP WROOM 32:
    - Vaya a Arduino IDE/Archivo/Preferencias/Gestor de URLs Adicionales de Tarjetas/  
    vea el recuadro rojo de la siguiente imagen.
![alt text](https://github.com/mauricioge/microcontroladores/blob/master/images/arduino-preferences.png "Arduino IDE/Archivo/Preferencias/Gestor de URLs Adicionales de Tarjetas/")

    + ESP8266: http://arduino.esp8266.com/stable/package_esp8266com_index.json
    + ESP32: http://dl.espressif.com/dl/package_esp32_index.json
- Aplicaciones:
    + [Arduino IDE](https://www.arduino.cc/en/main/software/)
- Librerías para Arduino:
    + [WiFi101 (de Arduino)](https://github.com/arduino-libraries/WiFi101)
    + [ESP8266WiFi (de ESP8266 community)](https://github.com/esp8266/Arduino)
    + [WiFi (de Espressif)](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi)
    + [MySQL Connector Arduino (de Dr. Charles Bell)](https://github.com/ChuckBell/MySQL_Connector_Arduino)
    + [ArduinoJson (de Benoit Blanchon)](https://github.com/bblanchon/ArduinoJson)
    + [Firebase ESP8266 (de Mobitz)](https://github.com/mobizt/Firebase-ESP8266)
    + [Adafruit Sensor (de Adafruit)](https://github.com/adafruit/Adafruit_Sensor)
    + [Adafruit DHT (de Adafruit)](https://github.com/adafruit/DHT-sensor-library)
    + [Adafruit MQTT Library (de Adafruit)](https://github.com/adafruit/Adafruit_MQTT_Library)
