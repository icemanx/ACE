#include <Ace.h>

Ace ace(10,13,12,14,2,0,4,5);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Angle: ");
  int value = ace.read();
  float degree = map(value,0,128,0,360);
  Serial.println(degree);
  delay(100);
}