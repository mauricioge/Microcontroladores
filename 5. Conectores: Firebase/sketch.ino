// Sketch original Arduino IDE\Examples\FirebaseArduino\FirebaseDemo_ESP8266
// Adaptado por: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Placa: NodeMCU V1

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>     // Por Benoit Blanchon | https://github.com/bblanchon/ArduinoJson
#include <FirebaseESP8266.h> // Por Mobizt          | https://github.com/mobizt/Firebase-ESP8266
#include "secrets.h" // Info sensible en "secrets.h"

void setup() {
  Serial.begin(9600);

  // conectar a wifi.
  WiFi.begin(SECRET_SSID, SECRET_PASS);
  Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("conectado: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(SECRET_FIREBASE_HOST, SECRET_FIREBASE_AUTH);
}

int n = 0;

void loop() {
  Firebase.setFloat("tmp", 42.0);  // set value
  if (Firebase.failed()) {  // handle error
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  Firebase.setFloat("hmd", 47.0);  // set value
  if (Firebase.failed()) {  // handle error
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("tmp: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  Firebase.setString("mac", "84:0D:8E:AB:D4:5B");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // append a new value to /logs
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);
}
