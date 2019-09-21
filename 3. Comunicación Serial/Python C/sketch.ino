// Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Cada 5 segundos envía una línea de datos por medio del puerto serial
// prg-C.py lee todo lo que la placa envía por el puerto serial
// Placas: ESP32 | MKR1000 | NodeMCU V1 | ESP-01

String rndTmp;
String rndHmd;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Ambas variables son alimentadas por valores random
  rndTmp = random(50);
  rndHmd = random(80);

  // Las variables son enviadas al puerto serial
  Serial.println("A4:CF:12:04:CB:1C, " + rndTmp + ", " + rndHmd);
  delay(5000);
}
