#include <dht.h>
#include <LiquidCrystal.h>
#include <math.h>
#include <IRremote.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 9;
const int echoPin = 10;
float duration, distance;

const int receiver = 8; 

IRrecv ir_receiver(receiver);           
decode_results results; 

dht DHT;
#define DHT11_PIN 7

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  ir_receiver.enableIRIn();
  ir_receiver.blink13(true);
  lcd.setCursor(0,0);
  lcd.print("Welcome");
  delay(1000);
  lcd.setCursor(0,0);
  if(int counter = 0){
    lcd.print("What will we be doing today?");
    counter++; };
  delay(700);
  scroll();
  delay(1000);
  menu();
}


void loop() {
  // put your main code here, to run repeatedly:     
  if (ir_receiver.decode(&results)){
      Serial.println(results.value, HEX);
     // menu_switch(results.value);
      ir_receiver.resume();} 
 }

void scroll(){
   // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(450);
  }
}

void menu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1 Distance");
  lcd.setCursor(0,1);
  lcd.print("2 Temp/Humiditiy");
}

  /*if (ir_receiver.decode(&results))

  {
    Serial.println(results.value, HEX);
    translateIR(); 
    ir_receiver.resume(); 
    delay(200); */


/* void translateIR() 

{
  int sensorValue=0;
  sensorValue = digitalRead(led);
  
  switch(results.value){

  case 0x20DF10EF:
    if (sensorValue==0){
      
      Serial.println(" ON "); 
      digitalWrite(led, HIGH); 
      break;
    }
    if (sensorValue==1){
      
      Serial.println(" OFF "); 
      digitalWrite(led, LOW); 
      break;
    }
    
    case 0x20DFD02F:
    if (sensorValue==0){
      Serial.println(" BLINK ");
      for(int i=1;i<5;i++){
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
      }
      break;
  }
  default: 
    Serial.println(" other button   ");
  }
} */
