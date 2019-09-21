# Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019
# Lee y muestra la info que pasa por el puerto serial
# La placa le envía datos por medio del puerto serial

import serial

# Creo una instancia del objeto serial
sd = serial.Serial('COM3', 9600)

while 1:
    # Muestro cada línea que pasa por el objeto sd
    print(sd.readline())
    # Muestro cada línea que pasa por el objeto sd pero la decodifico antes
    # print(sd.readline().decode('ascii'))
