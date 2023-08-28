int L_ENL=13;
int R_ENL=12;
int RPWML=11;
int LPWML=10;
int L_ENR=8;
int R_ENR=7;
int RPWMR=6;
int LPWMR=5;
int R1=2;
int R2=9;
int i;
int state = 0;
#include <SoftwareSerial.h>
SoftwareSerial mySer(3, 4);//RX TX

void setup() {
  pinMode(RPWML,OUTPUT);
  pinMode(LPWML,OUTPUT);
  pinMode(RPWMR,OUTPUT);
  pinMode(LPWMR,OUTPUT);
  pinMode(R_ENL,OUTPUT);
  pinMode(L_ENL,OUTPUT);
  pinMode(R_ENR,OUTPUT);
  pinMode(L_ENR,OUTPUT);

  digitalWrite(R_ENL,HIGH);
  digitalWrite(L_ENL,HIGH);
  digitalWrite(R_ENR,HIGH);
  digitalWrite(L_ENR,HIGH);
  //Serial.begin(9600); // Default communication rate of the Bluetooth module
  mySer.begin(9600);
}

void loop() {
 if(mySer.available() >0){
     state = mySer.read(); 
 }
   if (state == '0') {
  analogWrite(LPWML,0); //Turn off all
  analogWrite(RPWML,0);
  analogWrite(LPWMR,0);
  analogWrite(RPWMR,0);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  delay(0.000062255);
 //state = 0;
 }
  else if (state == '1') {
  analogWrite(LPWML,200);
  analogWrite(RPWML,0);
  analogWrite(LPWMR,200);
  analogWrite(RPWMR,0);
  delay(0.000062255);
  state = 0;
 }
  else if (state == '2') {
  analogWrite(LPWML,0); // back
  analogWrite(RPWML,255);
  analogWrite(LPWMR,0);
  analogWrite(RPWMR,255);
  delay(0.000062255);
  state = 0;
 }
 else if (state == '5') {
  analogWrite(LPWML,255); // right
  analogWrite(RPWML,0);
  analogWrite(LPWMR,0);
  analogWrite(RPWMR,0);
  delay(0.000062255);
  state = 0;
 }
 else if (state == '6') {
  analogWrite(LPWML,255); // right2
  analogWrite(RPWML,0);
  analogWrite(LPWMR,0);
  analogWrite(RPWMR,255);
  delay(0.000062255);
  state = 0;
 }
 else if (state == '3') {
  analogWrite(LPWML,0); // left
  analogWrite(RPWML,0);
  analogWrite(LPWMR,255);
  analogWrite(RPWMR,0);
  delay(0.000062255);
  state = 0;
 }
 else if (state == '4') {
  analogWrite(LPWML,0); // left2
  analogWrite(RPWML,255);
  analogWrite(LPWMR,255);
  analogWrite(RPWMR,0);
  delay(0.000062255);
  state = 0;
 }
 else if (state == '7') {
  analogWrite(LPWML,255); // Boost
  analogWrite(RPWML,0);
  analogWrite(LPWMR,255);
  analogWrite(RPWMR,0);
  analogWrite(R1, 255);
  analogWrite(R2, 255);
  delay(0.000062255);
  state = 0;
 }
}
