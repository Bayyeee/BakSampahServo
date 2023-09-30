#include <Servo.h>

Servo motorServo;
const int trigPin = D1;  // Pin trig sensor ultrasonik
const int echoPin = D2;  // Pin echo sensor ultrasonik
const int openAngle = 180;  // Sudut untuk membuka penutup bak sampah
const int closeAngle = 0;  // Sudut untuk menutup penutup bak sampah
const int triggerDistance = 100;  // Jarak untuk membuka penutup (dalam cm)

void setup() {
  motorServo.attach(D3);  // Hubungkan motor servo ke pin D3
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  Serial.begin(9600);  // Inisialisasi Serial Monitor
}

void loop() {
  // Mengukur jarak menggunakan sensor ultrasonik
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // Hitung jarak dalam cm

  // Tampilkan jarak pada Serial Monitor
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

  // Mengecek jarak dan menggerakkan motor servo sesuai
    if (distance < triggerDistance) {
    motorServo.write(openAngle);  // Membuka penutup bak sampah
    delay(500);  // Tunggu selama 1 detik
    } else {
    motorServo.write(closeAngle);  // Menutup penutup bak sampah
    delay(500);  // Tunggu selama 1 detik
    }
}