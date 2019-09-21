// Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019

// #include <WiFi.h> // Placa: ESP32
#include <WiFi101.h> // Placa: MKR1000
#include "secrets.h" //Info sensible

int status = WL_IDLE_STATUS;
String mac;

void setup() {
  Serial.begin(9600);
  delay(2000);

  while (status != WL_CONNECTED) {
    Serial.print("Intentando conectar a: ");
    Serial.println(SECRET_SSID);
    status = WiFi.begin(SECRET_SSID, SECRET_PASS); // Intenta conectar a red WiFi
    delay(5000); // espera 5 segundos para conectarse
  }
  printWifiStatus(); // muestra el estado de la conexion WiFi
  printMacAddress(); // muestra la dirección MAC del dispositivo
}

void loop() {
  // acá colocamos todo lo
  // que debe realizarse mientras
  // está conectado a WiFi.
}

void printWifiStatus() // muestra el status de la conexión WiFi
{
  // muestra el nombre de la red a la que esta conectado
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // muestra IP asignada
  IPAddress ip = WiFi.localIP();
  Serial.print("IP asignada: ");
  Serial.println(ip);

  // muestra la intensidad de la señal
  long rssi = WiFi.RSSI();
  Serial.print("intensidad de la señal (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void printMacAddress() // muestra la dirección MAC de la placa
{
  byte macB[6];
  WiFi.macAddress(macB);
  
  for (int i = 0; i < 6; i++) {
    String pos = String((uint8_t)macB[i], HEX);
    if (macB[i] <= 0xF) pos = "0" + pos;
    pos.toUpperCase();
    mac += pos;
    if (i < 5) mac += ":";
  }
  
  Serial.println(mac); // dirección MAC del dispositivo
}
