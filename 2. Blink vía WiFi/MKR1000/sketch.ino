// Sketch original Arduino IDE\Examples\WiFi101\SimpleWebServerWiFi
// Adaptado por: mauricioge <mauricioge@gmail.com> 20/Ago/2019

//#include <WiFi.h>// Placa: ESP32
#include <WiFi.h>// Placa: MKR1000
#include "secrets.h" // Info sensible en "secrets.h"

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);      // inicializo la comunicación serial
  pinMode(LED, OUTPUT);    // establecemos LED como pin de salida

  // intenta conectarse a red WiFi
  while ( status != WL_CONNECTED) {
    Serial.print("Conectando a: ");
    Serial.println(SECRET_SSID); // muestra el nombre de la red (SSID);
    status = WiFi.begin(SECRET_SSID, SECRET_PASS); // Conectar a red WPA/WPA2
    delay(10000);    // damos 10 segundos para que conecte
  }
  
  server.begin();    // inicia el servidor web en el puerto 80
  printWiFiStatus(); // muestra el estado de la conexión
}

void loop() {
  WiFiClient client = server.available();   // a la escucha de peticiones

  if (client) {                             // si recibe una petición,
    Serial.println("----------");           // muestra un mensaje via puerto serial
    String currentLine = "";                // crea una cadena para mantener datos que provienen del cliente
    while (client.connected()) {            // mientras (while) el cliente esté conectado
      if (client.available()) {             // si hay bytes que leer del cliente,
        char c = client.read();             // lee un byte, entonces
        Serial.write(c);                    // lo muestra via puerto serial
        if (c == '\n') {                    // si el byte es un caracter "newline"

          // si la linea actual está en blanco, recibirás dos caracteres "newline" seguidos.
          // eso es el fin de la petición HTTP del cliente, por lo tanto, responda.
          if (currentLine.length() == 0) {
            // Los encabezados HTTP siempre inician con un código de respuesta (ej. HTTP/1.1 200 OK)
            // y un content-type para que el cliente sepa lo que recibirá, luego una línea en blanco.
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
            client.println("  <p>LED: <a href=\"/H\">Encender</a> / <a href=\"/L\">Apagar</a></p>");
            client.println("</body>");
            client.println("</html>");

            // La respuesta HTTP finaliza con otra línea en blanco
            client.println();
            // finaliza el ciclo while
            break;
          }
          else {      // si recibe un caracter newline, vacíe la variable currentLine
            currentLine = "";
          }
        }
        else if (c != '\r') {    // si recibe cualquier otra cosa que no sea un caracter de retorno de carro,
          currentLine += c;      // añadalo al final de currentLine
        }

        // Revise si la solicitud del cliente fue "GET /H" or "GET /L"
        if (currentLine.endsWith("GET /H")) digitalWrite(LED, HIGH); // GET /H enciende el LED
        if (currentLine.endsWith("GET /L")) digitalWrite(LED, LOW);  // GET /L apaga el LED
      }
    }
    // cierra la conexión
    client.stop();
  }
}

void printWiFiStatus() // muestra el estado de la conexión WiFi
{
  // muestra el nombre de la red WiFi a la que está conectado
  Serial.print("Red: ");
  Serial.println(WiFi.SSID());

  // muestra la direccion IP asignada por el router
  IPAddress ip = WiFi.localIP();
  Serial.print("IP: ");
  Serial.println(ip);
  
  // muestra la intensidad de la senal
  long rssi = WiFi.RSSI();
  Serial.print("Intensidad de la señal: ");
  Serial.print(rssi);
  Serial.println(" dBm");
  
  // muestra la dirección IP para abrirla en el navegador
  Serial.print("Live action en > http://");
  Serial.println(ip);
}
