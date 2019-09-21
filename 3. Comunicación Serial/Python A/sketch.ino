// Autor: mauricioge <mauricioge@gmail.com> 20/Ago/2019
// Interactúa por medio del puerto serial con
// prg-A.py para encender el LED integrado

char sd; // Serial data
int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    sd = Serial.read();
    Serial.print(sd);

    if (sd == '1') {
      digitalWrite(LED, HIGH);
    } else if (sd == '0') {
      digitalWrite(LED, LOW);
    }
  }
}
