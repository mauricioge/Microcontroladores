# Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019
# Este programa lee el streaming del puerto serial
# y envía lo que lee a una base de datos MySQL.

import serial
import mysql.connector

# Creo una instancia del objeto sd (serial data) para ver lo que está pasando por el puerto serial
sd = serial.Serial('COM3', 9600)

while 1:
    # Creo el arreglo cad (cadena) que me permite separar cada línea en segmentos cada vez que encuentra una coma
    cad = sd.readline().decode('ascii').split(', ')
    
    # muestro el arreglo cad
    print(cad)
    
    # uso los segmentos para alimentar las variables que enviaré a la base de datos
    mac = cad[0]
    tmp = cad[1]
    hmd = cad[2]

    # creo cn (conexión) para conectarme a la base de datos
    cn = mysql.connector.connect(
      host="localhost",
      user="iot_admin",
      passwd="12345678",
      database="iot"
    )

    # creo csr (cursor) para manejar la consulta
    csr = cn.cursor()

    # creo la consulta
    sql = "INSERT INTO iot_th (id_th, mac, tmp, hmd) VALUES (UUID(), %s, %s, %s)"
    val = (mac, tmp, hmd)

    # ejecuto la consulta
    csr.execute(sql,val)

    # confirmo para crear el registro en la base de datos
    cn.commit()

    # luego de recibir respuesta, muestro un mensaje de confirmación
    print(csr.rowcount, "registro insertado.")

    # cierro el cursor
    csr.close()

    # cierro la conexión
    cn.close()
