// Sketch original Arduino IDE\Examples\ESP8266WiFi\WiFiManualWebServer
// Adaptado por: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Placas: ESP8266 ESP-01 / NodeMCU V1

#include <ESP8266WiFi.h> // Por: 
#include "secrets.h"     // Info sensible en "secrets.h"

WiFiServer server(80);   // Crea una instancia de servidor web en el puerto 80
String mac;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 0);

  // Conecta a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print(F("Conectando a: "));
  Serial.println(SECRET_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SECRET_SSID, SECRET_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("Conectado a WiFi."));

  // Iniciar el servidor
  server.begin();
  Serial.println(F("Servidor iniciado"));

  // Muestra la dirección IP
  Serial.println(WiFi.localIP());
    printMacAddress(); // muestra la dirección MAC del dispositivo

}

void loop() {
  // Verifica si algún cliente se ha conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println(F("Cliente nuevo"));

  client.setTimeout(5000); // default 1000

  // Lee la primera línea de la petición
  String req = client.readStringUntil('\r');
  Serial.println(F("Petición: "));
  Serial.println(req);

  // Match the request
  int val;
  if (req.indexOf(F("/gpio/0")) != -1) {
    val = 0;
  } else if (req.indexOf(F("/gpio/1")) != -1) {
    val = 1;
  } else {
    Serial.println(F("petición no válida"));
    val = digitalRead(LED);
  }

  // Encender o apagar LED acorde a la petición
  digitalWrite(LED, val);

  // read/ignore the rest of the request
  // do not client.flush(): it is for output only, see below
  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  // Send the response to the client
  // it is OK for multiple small client.print/write,
  // because nagle algorithm will group them into one single packet
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  // el contenido de la respuesta HTTP sigue al encabezado
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("<head>");
  client.println("  <meta charset=utf-8>");
  client.println("  <meta name=viewport content=\"width=device-width, initial-scale=1.0\">");
  client.println("  <title>WiFi - Blink</title>");
  client.println("  <style>");
  client.println("    body{background-color:#333;color:#EEE;font-family:Segoe,Verdana,sans-serif}");
  client.println("    a:link,a:visited{color:orange;text-decoration:none}");
  client.println("    a:hover,a:active{color:orange;text-decoration:underline}");
  client.println("  </style>");
  client.println("</head>");
  client.println("<body>");
  client.println("  <p>LED: <a href=\"/gpio/1\">Encender</a> / <a href=\"/gpio/0\">Apagar</a></p>");
  client.println("</body>");
  client.println("</html>");

  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
}

void printMacAddress() // muestra la dirección MAC de la placa
{
  byte macB[6];
  WiFi.macAddress(macB);
 
  for (int i = 0; i < 6; i++) 
  {
    String pos = String((uint8_t)macB[i], HEX);
    if (macB[i] <= 0xF) pos = "0" + pos;
    pos.toUpperCase();
    mac += pos;
    if (i < 5) mac += ":";
  }
  
  Serial.println(mac);
}
