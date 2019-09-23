# MICROCONTROLADORES

## RENUNCIA DE RESPONSABILIDAD: 📢
El código incluído en este repositorio se ofrece **"COMO ESTÁ"**, sin garantías o responsabilidad de ningún tipo. Usted es el único responsable de usarlo. Los scripts, incluyendo URLs y otras referencias a sitios en Internet, podrían cambiar sin previo aviso. Este documento no le autoriza a nada y no le faculta con ningún derecho legal ni propiedad intelectual. Puede copiar y usar este código con el único fin de usarlo como referencia personal.

### DESCRIPCIÓN: 🚀
1. Lee los datos que vienen del sensor.
2. Se conecta a Internet vía WiFi.
3. Se conecta al servidor al que quiere enviar los datos.
4. Envía los datos usando el protocolo HTTP.
5. PHP recibe y envía los datos a MySQL.
6. Muestra mediante el monitor serial que recibió los datos.
7. PHP muestra los datos almacenados.

**HARDWARE:** ⚙
- Placas: Arduino MKR1000, ESP-01, NodeMCU V1, ESP WROOM 32.
- Sensor: DHT11.

**SOFTWARE:** 💾
- Aplicaciones:
    + [Arduino IDE](https://www.arduino.cc/en/main/software/)
    + [MySQL (motor + herramientas cliente)](https://dev.mysql.com/downloads/workbench/)
    + Editor de texto plano (Ej. Block de notas).
- Librerías para Arduino:
    + [WiFi101 (de Arduino)](https://github.com/arduino-libraries/WiFi101)
    + [ESP8266WiFi (de ESP8266 community)](https://github.com/esp8266/Arduino)
    + [WiFi (de Espressif)](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi)
    + [Adafruit Sensor (de Adafruit)](https://github.com/adafruit/Adafruit_Sensor)
    + [Adafruit DHT (de Adafruit)](https://github.com/adafruit/DHT-sensor-library)
- Placas (Arduino IDE/Archivo/Preferencias/Gestor de URLs Adicionales de Tarjetas/):
    + [ESP8266](http://arduino.esp8266.com/stable/package_esp8266com_index.json)
    + [ESP32](http://dl.espressif.com/dl/package_esp32_index.json)
- Cuentas gratuitas en la nube: ☁
    + [Hosting](https://www.000webhost.com/)
