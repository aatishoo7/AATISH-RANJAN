
#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial mySerial(9,10);
int sensorpin=A0;
int buzzerpin=11;
int smokesensor=6;
int smokesensorvalue;
int flamesensorpin=3;
int flamesensorvalue;
int sensorvalue;
int motorpin=3;
LiquidCrystal lcd(2,3,4,5,6,7);
Servo servo;
void setup()
{
  servo.attach(5);
  delay(100);
  servo.write(180);
  delay(100);
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
  pinMode(buzzerpin,OUTPUT);
  pinMode(flamesensorpin,INPUT);
  lcd.begin(16,2);
  lcd.home();
  lcd.print("the val is:");
  // put your setup code here, to run once:

}

void loop() 
{
  lcd.print("the");
  delay(5000);
   sensorvalue=analogRead(sensorpin);
   smokesensorvalue=analogRead(smokesensor);
   flamesensorvalue=analogRead(flamesensorpin);
   delay(200);
  if(sensorvalue>450)
  { servo.write(80);
    delay(2000);
    servo.detach();
    analogWrite(buzzerpin,20);
    if(mySerial.available()>0);
    Serial.write(mySerial.read());
    SendMessage();
    delay(50);
    
  }
  else
  { analogWrite(buzzerpin,0);
    delay(5);
  }
  if(smokesensorvalue>245)
  {
  
     
  }
  if(flamesensorvalue>600)
  { 
    analogWrite(buzzerpin,20);
  }
 
  lcd.setCursor(5,2);
  lcd.print(int(sensorvalue));
  Serial.print("the alcohol sensor value is");
  Serial.println(sensorvalue);
  Serial.println("the smoke sensor value is");
  Serial.println(smokesensorvalue);
  Serial.println("the flame sensor value is");
  Serial.println(flamesensorvalue);
  delay(900);
  
  
  // put your main code here, to run repeatedly:


}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918837240699\"\r");
  delay(1000);
  mySerial.println("the driver is drunk ");
  mySerial.println("the sensor value is");
  mySerial.println(sensorvalue);
  mySerial.println("the location is MOHANLAL SUKHADIA UNIVERSITY");
  delay(100);
  
  mySerial.println((char)26);
  delay(1000);
}  


