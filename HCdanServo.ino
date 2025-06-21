#include <Servo.h>
#include <NewPing.h>

// Motor control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 8;
const int RightMotorForward = 5;
const int RightMotorBackward = 6;

// Enable pins for PWM speed control
const int ENA = 3;  // Enable motor kiri
const int ENB = 4; // Enable motor kanan

// Ultrasonic sensor pins
#define trig_pin 10
#define echo_pin 9
#define maximum_distance 200

boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

void setup(){
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  servo_motor.attach(12);
  servo_motor.write(95);
  
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  int distanceRight = 0;
  int distanceLeft  = 0;
  delay(50);

  // Jika ada objek di depan dalam jarak 20 cm
  if (distance <= 20) {
    moveStop();
    delay(300);

    // Mundur sebentar untuk menjauh dari objek di depan
    moveBackward();
    delay(300);
    moveStop();
    delay(300);

    // Cek jarak kanan dan kiri
    distanceRight = lookRight();
    delay(300);
    distanceLeft  = lookLeft();
    delay(300);

    // --- PERUBAHAN LOGIKA UTAMA ---
    // Jika kanan dan kiri sama‑sama sempit (<20 cm), robot mundur lagi
    if (distanceRight < 20 && distanceLeft < 20) {
      moveBackward();
      delay(300);
      turnRight2();
    } else {
      // Jika salah satu sisi lebih lapang, belok ke sisi tersebut
      if (distanceRight >= distanceLeft) {
        turnRight();
      } else {
        turnLeft();
      }
    }

    moveStop();
  } else {
    // Tidak ada halangan di depan, jalan lurus
    moveForward();
  }

  // Perbarui jarak depan untuk siklus berikutnya
  distance = readPing();
}


int lookRight(){  
  servo_motor.write(0);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(95);
  return distance;
}

int lookLeft(){
  servo_motor.write(190);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(95);
  return distance;
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void moveStop(){
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void moveForward(){
  if(!goesForward){
    goesForward = true;

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);

    analogWrite(ENA, 255); // Kecepatan 0–255
    analogWrite(ENB, 160);
  }
}

void moveBackward(){
  goesForward = false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  analogWrite(ENA, 220);
  analogWrite(ENB, 180);
}

void turnRight(){
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  delay(300);
}

void turnRight2(){
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  delay(480);
}

void turnLeft(){
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  delay(300);
}