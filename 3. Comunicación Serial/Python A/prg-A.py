# Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019
# Envía información vía puerto serial

import serial

# Creo el objeto sd (serial data) para usarlo como canal de comunicación de doble vía
sd = serial.Serial('COM3', 9600)

while 1:
  sd.write(input("Introduzca 1 para encender y 0 para apagar el LED: ").encode())
