#include <ESP32Servo.h>

// Assign variables to pin numbers  
const int servoPin = 10;
const int trigPin = 3;
const int echoPin = 4;
// Assign variable for open angle (ex. 160 may vary)
int open_angle = 90;
// Assign variable for close angle (ex. 20 may vary)
int close_angle = 0;
// Initialize servo object with your servo name
Servo myServo;

bool isOpen = false;

void setup() {
  // Setup Trig and Echo pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Attach object of your servo name to the physical servo
  myServo.attach(servoPin);
  // Initialize servo to close angle
  myServo.write(close_angle);
  Serial.begin(115200);
}

void loop() {
  // Send pulses
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  // Calculate distance
  long duration = pulseIn(echoPin, HIGH); // Takes measurement of pulse in microseconds
  float distance = duration / 58.0;        // // conversion to cm
  Serial.print("Distance: ");
  Serial.print(distance);   
  Serial.println(" cm.");
  // Write servo angle to open or close based on a distance threshold in cm (value may vary)
  if (distance > 0 && distance < 20){
    myServo.write(open_angle);
    isOpen = true;
  } else {
    myServo.write(close_angle);
  }
  delay(100);
}