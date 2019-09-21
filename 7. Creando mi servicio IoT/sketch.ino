// Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019

#include <WiFi101.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include "secrets.h" // Info sensible en "secrets.h"

String mac;
String tmp;
String hmd;

int status = WL_IDLE_STATUS;

DHT_Unified dht(DHTPIN, DHTTYPE);
WiFiClient client;

// dirección del servidor al que enviará los datos
// char server[] = "iot-sandbox.000webhostapp.com";
char server[] = "192.168.43.226"; // dirección IP del servidor MySQL

// última vez que se conectó al servidor, en milisegundos
unsigned long lastConnectionTime = 0;

// delay entre actualizaciones, en milisegundos
const unsigned long postingInterval = 10L * 1000L;

void setup() {
  // inicializo el puerto serial
  Serial.begin(9600);
  // intenta conectarse a la red Wifi
  while (status != WL_CONNECTED)
  {
    Serial.print("Intentando conexión a SSID: ");
    Serial.println(SECRET_SSID);
    status = WiFi.begin(SECRET_SSID, SECRET_PASS);
    delay(10000);
  }
  
  printWiFiStatus();
  printMacAddress();
  
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
}

void loop() {
  delay(10000);

  sensors_event_t event;

  // obtenemos temperatura
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.print(F("ND"));
    tmp = "ND";
  }
  else {
    tmp = event.temperature;
    Serial.print(tmp);
  }

  // obtenemos humedad
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.print(F("ND"));
    hmd = "ND";
  }
  else {
    hmd = event.relative_humidity;
    Serial.print(F(" | "));
    Serial.println(hmd);
  }

  // Si hubiera datos entrantes de la conexión se
  // envían al puerto serial (solo para depurar)
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // 10 segs después de la última conexión, intente reconectar y envíe datos
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}

// envía la petición
void httpRequest() {
  // cierra cualquier conexión antes de enviar una nueva solicitud
  client.stop();
  client.flush();

  // si la conexión tiene éxito
  if (client.connect(server, 80)) {
    Serial.println("Conectando...");
    // envía la petición HTTP
    client.println("GET /iot.php?mac=" + mac + "&tmp=" + tmp + "&hmd=" + hmd + " HTTP/1.1");
    Serial.print(server);
    Serial.println("/iot.php?mac=" + mac + "&tmp=" + tmp + "&hmd=" + hmd + " HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("User-Agent: MKR1000/1.0");
    client.println("Connection: close");
    client.println();
    Serial.println("Datos enviados");

    // registra la hora en que se realizó la última conexión
    lastConnectionTime = millis();
  }
  else {
    Serial.println("Intento de conexión fallido");
  }
}

void printWiFiStatus() // muestra el estado de la conexión WiFi
{
  Serial.print("Red WiFi: ");                     // muestra el SSID de la red a la que está conectado
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();                  // muestra la dirección IP que le asignó el router
  Serial.print("Dirección IP: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();                        // muestra la potencia de la señal recibida
  Serial.print("Intensidad de la señal (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
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
