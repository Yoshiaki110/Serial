#include <M5StickC.h>

HardwareSerial serial_ext(2);

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, 0, 26); // EXT_IO
//  serial_ext.begin(115200, SERIAL_8N1, 26, 36);

  M5.begin();
 
  // LED ON(GPIO_NUM_10 or M5_LED)
  pinMode(GPIO_NUM_10, OUTPUT);
}

unsigned long n = 0;
void loop() {
  if (++n < 10000) {
    digitalWrite(GPIO_NUM_10, HIGH);    
  } else {
    digitalWrite(GPIO_NUM_10, LOW);    
  }
  // PCからの入力
  if (Serial.available() > 0) { // 受信したデータが存在する
    n = 0;
    int incomingByte = Serial.read(); // 受信データを読み込む
    Serial1.write(incomingByte);
  }
  // Raspberry Piからの入力
  if (Serial1.available() > 0) { // 受信したデータが存在する
    n = 0;
    int incomingByte = Serial.read(); // 受信データを読み込む
    Serial.write(incomingByte);
  }
}
