//This is a combined and tuned skecth that uses both libraries to detect motion and send response over GSM.
//GENERAL DECLARATIONS

//SHARP SECTION
#include <SharpIR.h>
#define ir A0
#define model 20150
SharpIR SharpIR(ir, model);

//SIM800L SECTION
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); 
char incomingByte; 
String inputString;
int led = 13;

// GENERAL VOID SETUP

void setup() {
  
   // SHARP SECTION
      Serial.begin(9600);
  
  //SIM800L SECTION
      pinMode(led, OUTPUT);
      pinMode(LED_BUILTIN, OUTPUT);
      //Serial.begin(9600);
      mySerial.begin(9600); 
      // Check if you're currently connected to SIM800L 
      while(!mySerial.available()){
        mySerial.println("AT");
        delay(1000); 
      //Serial.println("connecting....");
        }
      //Serial.println("Connected..");  
      mySerial.println("AT+CMGF=1\r\n");  //Set SMS Text Mode 
      delay(1000);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //procedure, how receiving of new messages from the network
      delay(1000);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages
      delay(1000);
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);
  
}
//GENERAL VOID LOOP
void loop() {
  delay(500);   

  unsigned long pepe1=millis();  // takes the time before the loop on the library begins

  int dis=SharpIR.distance();  // this returns the distance to the object you're measuring


  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);
  
  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
  Serial.print("Time taken (ms): ");
  Serial.println(pepe2); 



  if ((dis > 101) && (dis < 179)){
 analogWrite(11,255);
  }
  else{
  analogWrite(11,0);
  }

  
if (dis>= 180){
  analogWrite(12,255);
  }
  else{
  analogWrite(12,0);
  }

  
  if (dis<= 100){
 analogWrite(13,255);
  }
  else{
  analogWrite(13,0);
  }
  
delay(10);

}

