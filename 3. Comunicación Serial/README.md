# 3. COMUNICACIÓN SERIAL (CON PYTHON)

## RENUNCIA DE RESPONSABILIDAD: 📢
El código incluído en este repositorio se ofrece **"COMO ESTÁ"**, sin garantías o responsabilidad de ningún tipo. Usted es el único responsable de usarlo. Los scripts, incluyendo URLs y otras referencias a sitios en Internet, podrían cambiar sin previo aviso. Este documento no le autoriza a nada y no le faculta con ningún derecho legal ni propiedad intelectual. Puede copiar y usar este código con el único fin de usarlo como referencia personal.

### DESCRIPCIÓN: 🚀
1. Enciende y apaga el LED integrado de la placa desde Python por medio del puerto serial.
2. Envía datos a Python por medio del puerto serial, los procesa y los muestra.
3. Envía datos a Python por medio del puerto serial, los procesa y los envía a MySQL.

**ARCHIVOS:** ⚙
- **sketch.ino**

**HARDWARE:** ⚙
- Placas: Arduino MKR1000, ESP-01, NodeMCU V1, ESP WROOM 32.
- Actuadores, sensores o módulos: LEDs integrados, DHT11, MFRC522.

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
