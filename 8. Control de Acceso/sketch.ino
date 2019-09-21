// Sketch original 1: Arduino IDE/Examples/MFRC522/DumpInfo
// Sketch original 2: Arduino IDE/Examples/MFRC522/ChangeUID
// Adaptado por: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Placa: Arduino MKR1000

#include <WiFi101.h>
#include <SPI.h>
#include <MFRC522.h> // Por Miguel Balboa | https://github.com/miguelbalboa/rfid
#include "secrets.h" // Info sensible en el archivo "secrets.h"

int status = WL_IDLE_STATUS;
String uid;
String mac;

WiFiClient client;                                 // instancia de WiFiClient
MFRC522 mfrc522(SS_PIN, RST_PIN);                  // instancia del MFRC522
char server[] = "192.168.43.226";                  // servidor al que enviará los datos
unsigned long lastConnectionTime = 0;              // última vez que se conectó al servidor (milisegundos)
const unsigned long postingInterval = 10L * 1000L; // retraso calculado entre actualizaciones (milisegundos)

void setup() {
  Serial.begin(9600);
  SPI.begin();        // Inicia el bus SPI
  mfrc522.PCD_Init(); // Inicia el MFRC522

  while (status != WL_CONNECTED)
  {
    Serial.print("Intentando conexión a SSID: ");
    Serial.println(SECRET_SSID);
    status = WiFi.begin(SECRET_SSID, SECRET_PASS); // intento conectarme a WiFi
    delay(10000);
  }
  
  printWiFiStatus();
  printMacAddress();
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) return;
  if ( ! mfrc522.PICC_ReadCardSerial()) return;

  for (int i = 0; i < mfrc522.uid.size; i++) uid += String(mfrc522.uid.uidByte[i], HEX);

  Serial.println(uid);

  // 10 segs despues de la ultima conexión, intente reconectar y envíe datos
  if (millis() - lastConnectionTime > postingInterval) httpRequest();
  uid = "";
}

void httpRequest() // envía petición HTTP
{
  // cierra cualquier conexión antes de enviar una nueva solicitud
  client.stop();
  client.flush();

  if (client.connect(server, 80)) // si la conexión tiene éxito
  {
    Serial.println("Conectando...");
    // envía la petición HTTP
    client.println("GET /rfid/consulta.php?uid=" + uid + "&mac=" + mac + " HTTP/1.1");
    Serial.println("GET /rfid/consulta.php?uid=" + uid + "&mac=" + mac + " HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("User-Agent: MKR1000/1.0");
    client.println("Connection: close");
    client.println();
    Serial.println("Datos enviados");
    // registra la hora en que se realizó la conexión
    lastConnectionTime = millis();
  }
  else // sino logra establecer conexión
  {
    Serial.println("Intento de conexión fallido");
  }
  // Si hubiera datos entrantes de la conexión se
  // envían al puerto serial solo para depurar
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
}

void printWiFiStatus() {
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

void printMacAddress() // dirección MAC del dispositivo
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
