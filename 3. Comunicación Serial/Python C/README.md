# 3. COMUNICACIÓN SERIAL (CON PYTHON)

## RENUNCIA DE RESPONSABILIDAD: 📢
El código incluído en este repositorio se ofrece **"COMO ESTÁ"**, sin garantías o responsabilidad de ningún tipo. Usted es el único responsable de usarlo. Los scripts, incluyendo URLs y otras referencias a sitios en Internet, podrían cambiar sin previo aviso. Este documento no le autoriza a nada y no le faculta con ningún derecho legal ni propiedad intelectual. Puede copiar y usar este código con el único fin de usarlo como referencia personal.

### DESCRIPCIÓN: 🚀
Envía datos a Python por medio del puerto serial. Python los procesa y los envía a MySQL.

**ARCHIVOS:** ⚙
1. **iot_th.sql**: Crea la estructura de la tabla "iot_th" 
    1. Lea y razone el código.
    2. Trate de interpretar/entender el propósito del código.
    3. Ejecútelo.
2. **sketch.ino**
    1. Súbalo a una placa.
    2. Ejecútelo.
    3. Abra el monitor serial para verificar que está funcionando.
    4. Cierre el monitor serial
3. **prg-C.py**
    1. Lea y razone el código.
    2. Trate de interpretar/entender el propósito del código.
    3. Ejecútelo.
    4. Abra la base de datos.
    5. Revise los últimos registros guardados en la tabla "iot_th".

**HARDWARE:** ⚙
- Placas: Arduino UNO R3, Arduino MKR1000, ESP-01, NodeMCU V1, ESP WROOM 32.

**SOFTWARE:** 💾
- Aplicaciones:
    + [Arduino IDE](https://www.arduino.cc/en/main/software/)
    + [Python](https://www.python.org/downloads/)
    + [MySQL (motor + herramientas cliente)](https://dev.mysql.com/downloads/workbench/)
- Librerías para Python:
    + [pyserial](https://pypi.org/project/pyserial/)
    + [mysql connector python](https://pypi.org/project/mysql-connector-python/)
- Placas (Arduino IDE/Archivo/Preferencias/Gestor de URLs Adicionales de Tarjetas/):
    + [ESP8266](http://arduino.esp8266.com/stable/package_esp8266com_index.json)
    + [ESP32](http://dl.espressif.com/dl/package_esp32_index.json)
