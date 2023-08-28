#define DR 11 //IN driver
#define DL 12
#define R1 10 //relay
#define R2 9
#define R_EN 8 //INH driver
#define L_EN 7
int state = 0;
#include <SoftwareSerial.h>

SoftwareSerial mySer(3, 4); //RX TX

void setup() {
 pinMode(DR, OUTPUT);
 digitalWrite(DR, LOW);
 pinMode(DL, OUTPUT);
 digitalWrite(DL, LOW);
  pinMode(R1, OUTPUT);
 digitalWrite(R1, LOW);
  pinMode(R2, OUTPUT);
 digitalWrite(R2, LOW);
 //Serial.begin(9600); // Default communication rate of the Bluetooth module
mySer.begin(9600);
}
void loop() {
 if(mySer.available() >0){
     state = mySer.read(); 

  }

 if (state == '0') {
 digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
 digitalWrite(DR, LOW); //turn off all
 digitalWrite(DL, LOW);
  digitalWrite(R1, LOW);
   digitalWrite(R2, LOW);
 //state = 0;
 }
 else if (state == '1') { //go
 digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
 digitalWrite(DR, HIGH);
digitalWrite(DL, HIGH);
 state = 0;
 }

 else if (state == '2') { //right

 digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
  digitalWrite(DR, LOW);
digitalWrite(DL, HIGH);
 state = 0;
 } 
 else if (state == '3') { //LEFT
digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
 digitalWrite(DR, HIGH);
digitalWrite(DL, LOW);
 state = 0;
 } 
  else if (state == '4') { //back
 
 digitalWrite(R_EN,LOW);
  digitalWrite(L_EN,LOW);
  digitalWrite(DR, HIGH);
digitalWrite(DL, HIGH);
 state = 0;
 }
  else if (state == '5') { //BOOST
 digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
 digitalWrite(DR, HIGH);
digitalWrite(DL, HIGH);
  digitalWrite(R1, HIGH);
   digitalWrite(R2, HIGH);
 state = 0;
 }
}
