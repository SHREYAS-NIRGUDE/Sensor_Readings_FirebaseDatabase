//CODE by SHREYAS
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "send-sensor-value-to-firebase-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "YmLXWXcWcV3aUy7J3jpbDivm4jFuBsCwkwiFeZ9g"
#define WIFI_SSID "SHREYAS_5G"
#define WIFI_PASSWORD "@tts_ssn"

#define TRIGGER 5
#define ECHO    4

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}
 
void loop() {
 
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  delay(1000);
}
