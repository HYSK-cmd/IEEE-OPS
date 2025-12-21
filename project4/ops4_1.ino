#include <ESP32Servo.h>

// Assign variable to pin number for Potentiometer
int PotPin = 4;
// Assign variable to pin number of Servo’s PWM pin
int ServoPin = 10;
// Initialize servo object with your servo name
Servo myServo;

                                
void setup() {
    // Configure the Potentiometer's pin behavior to INPUT
  pinMode(PotPin, INPUT);
    // Attach object of your servo name to the physical servo
  myServo.attach(ServoPin);
    // Configure the Serial baud rate to 115200
  Serial.begin(115200);
}
                                
void loop() {
    // Read potentiometer pin value
  int PotValue = analogRead(PotPin);
    // Set and map servo angle to the potentiometer pin value
  int servoAngle = map(PotValue, 0, 4095, 0, 180);
  myServo.write(servoAngle);


  Serial.print("Potentiometer Value: ");
  Serial.print(PotValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(servoAngle); // println adds a new line at the end
  delay(100);
}