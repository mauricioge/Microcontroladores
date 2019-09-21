// Sketch original Arduino IDE\Examples\Adafruit MQTT Library\mqtt_2subs_esp8266
// Adaptado por: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Placa: MKR1000

#include <WiFi101.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <SPI.h>
#include <Wire.h>

#include "arduino_secrets.h" // Guarde info sensible en el archivo "arduino_secrets.h"
char ssid[] = SECRET_SSID;   // SSID: Red WiFi a la que se quiere conectar
char pass[] = SECRET_PASS;   // Contraseña (WPA)

WiFiClient client;

// Inicializa un cliente MQTT al pasarle el cliente WiFi y los datos de acceso al servidor MQTT.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Las rutas MQTT de AIO siguen el patrón: <username>/feeds/<feedname>
Adafruit_MQTT_Subscribe led_builtin = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/LED_BUILTIN");

void setup() {
  pinMode(LED, OUTPUT);
  delay(5000);

  Serial.begin(9600);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  mqtt.subscribe(&led_builtin); // Suscripción MQTT al feed led_builtin
}

void loop() {
  MQTT_connect();

  Adafruit_MQTT_Subscribe *subscription;

  while (subscription = mqtt.readSubscription(5000)) {
    if (subscription == &led_builtin) {
      Serial.print(F("LED_BUILTIN: "));
      Serial.println((char *)led_builtin.lastread);

      if (strcmp((char *)led_builtin.lastread, "ON") == 0) {
        digitalWrite(LED, HIGH);
      }
      if (strcmp((char *)led_builtin.lastread, "OFF") == 0) {
        digitalWrite(LED, LOW);
      }
    }
  }
  // Envía un ping al servidor para mantener activa la conexión mqtt
  if (!mqtt.ping()) {
    mqtt.disconnect();
  }
}

// Función para conectar/reconectar al servidor MQTT
void MQTT_connect() {
  int8_t ret; // Se detiene si ya está conectado
  if (mqtt.connected()) return;

  Serial.println("Conectándose a MQTT...");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // Si se conecta devuelve 0
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Reintentando conexión a MQTT en 5 segundos...");
    mqtt.disconnect();
    delay(5000);  // espere 5 segundos
    retries--;
    if (retries == 0) {
      while (1);
    }
  }
  Serial.println("Conectado a MQTT");
}
