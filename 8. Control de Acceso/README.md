# MICROCONTROLADORES

## RENUNCIA DE RESPONSABILIDAD: 📢
El código incluído en este repositorio se ofrece **"COMO ESTÁ"**, sin garantías o responsabilidad de ningún tipo. Usted es el único responsable de usarlo. Los scripts, incluyendo URLs y otras referencias a sitios en Internet, podrían cambiar sin previo aviso. Este documento no le autoriza a nada y no le faculta con ningún derecho legal ni propiedad intelectual. Puede copiar y usar este código con el único fin de usarlo como referencia personal.

### DESCRIPCIÓN: 🚀
1. Se conecta a Internet vía WiFi.
2. Recibe el UID de la tarjeta leída por el MFRC522.
3. Se conecta al servidor al que quiere enviar los datos.
4. Envía los datos usando el protocolo HTTP.
5. PHP recibe y consulta los datos con MySQL.
6. PHP crea un registro de la consulta que acaba de realizar.
6. Muestra mediante el monitor serial que recibió los datos.
7. PHP muestra los datos almacenados.

**ARCHIVOS:**
- **sketch.ino**: Súbalo a la placa, ejecútelo y abra el monitor serial.
- **secrets.h**: Contiene los datos de acceso a la red WiFi y los datos de acceso a MySQL.
- **consulta.php**: Recibe una petición HTTP con los datos que le envía la placa y los re-envía a MySQL.
- **select.php**: Muestra los datos almacenados en MySQL.
- **historial.php**: muestra el historial de cada UID o dirección MAC en orden cronológico.
- **del.php**: Borra todos los registros almacenados en MySQL.
- **create_table.sql**: Script para re-crear la estructura de la tabla "iot_th".

**HARDWARE:** ⚙
- Placas:
    1. Arduino MKR1000
    2. ESP WROOM 32.
- Sensor: RFID MFRC522.

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
