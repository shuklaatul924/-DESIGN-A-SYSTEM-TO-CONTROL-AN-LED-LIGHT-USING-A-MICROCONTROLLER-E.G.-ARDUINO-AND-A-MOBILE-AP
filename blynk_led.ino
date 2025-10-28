#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Your_Blynk_Auth_Token";  // For Blynk App
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

int ledPin = D2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  digitalWrite(ledPin, pinValue);
}

void loop() {
  Blynk.run();
}
