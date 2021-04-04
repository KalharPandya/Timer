#include<Timer.h>

void test500(){
  Serial.println(500);
}
void test200(){
  Serial.println(200);
}
void test100(){
  Serial.println(100);
}
void test50(){
  Serial.println(50);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initTimer();
  timeManager.attachEvent(test500,500);
  timeManager.attachEvent(test200,200);
  timeManager.attachEvent(test100,100);
  timeManager.attachEvent(test50,50);
}

void loop() {

}