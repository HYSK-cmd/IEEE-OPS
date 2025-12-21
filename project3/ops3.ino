const int R_LED = 8;
const int G_LED = 10;
const int B_LED = 21;

const int PO1 = 0;
const int PO2 = 1;
const int PO3 = 4;

void setup() {
  pinMode(R_LED, OUTPUT);     // R_LED pin's behavior to OUTPUT
  pinMode(G_LED, OUTPUT);     // G_LED pin's behavior to OUTPUT
  pinMode(B_LED, OUTPUT);     // B_LED pin's behavior to OUTPUT*/
  pinMode(PO1, INPUT);        // Potentiometer's pin behavior to INPUT
  pinMode(PO2, INPUT);        // Potentiometer's pin behavior to INPUT
  pinMode(PO3, INPUT);        // Potentiometer's pin behavior to INPUT
  Serial.begin(115200);       // 115200 bits per second
}

void loop() {
  int val1 = analogRead(PO1);
  int val2 = analogRead(PO2);
  int val3 = analogRead(PO3);

  
  int r = map(val1, 0, 4095, 0, 255);
  int g = map(val2, 0, 4095, 0, 255);
  int b = map(val3, 0, 4095, 0, 255);

  analogWrite(R_LED, r);
  analogWrite(G_LED, g);
  analogWrite(B_LED, b);
}
