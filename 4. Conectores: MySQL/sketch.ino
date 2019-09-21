// Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Se conecta a la red WiFi y envía
// datos directamente al motor de MySQL.
// Placa: MKR1000

#include <SPI.h>
#include <WiFi101.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include "secrets.h"

char ins[]  = "INSERT INTO iot.iot_th (id_th, mac, tmp, hmd) VALUES (UUID(), '5F:E7:F5:05:F0:F8', '01.00', '01.00')"; // INSERT SQL

WiFiClient client;
MySQL_Connection cn((Client *)&client);
IPAddress srv(192, 168, 43, 226); // Datos de acceso remoto a MySQL (%)

void setup() {
  Serial.begin(9600);
  while (!Serial); // Esperamos que el puerto serial inicie

  // Inicia sección WiFi
  int status = WiFi.begin(SECRET_SSID, SECRET_PASS);
  if ( status != WL_CONNECTED) {
    Serial.println("No se pudo conectar a WiFi");
    while (true);
  }
  // Muestra información de la conexión
  else {
    Serial.println("Conectado a la red");
    IPAddress ip = WiFi.localIP();
    Serial.print("Dirección IP: ");
    Serial.println(ip);
  }
  // Finaliza sección WiFi

  Serial.println("Conectando...");
  if (cn.connect(srv, 3306, SECRET_MYSQL_USER, SECRET_MYSQL_PASS)) {
    delay(1000);
  } else {
    Serial.println("Conexión fallida.");
  }
}

void loop() {
  delay(10000);

  Serial.println("Registrando datos.");
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&cn);
  cur_mem->execute(ins); // Ejecuta la consulta // Nota: puesto que no devuelve resultados, no necesitamos leer datos de retorno.
  delete cur_mem;
}
