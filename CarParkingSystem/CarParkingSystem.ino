/*
Project Name: IOT based smart vahicle parking system

Mirzana Jannat Piya
Roll 1704018

*/


#include <Servo.h>
#include <LiquidCrystal.h> 
#include <Wire.h>  
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;  // create servo object to control a servo

//************** Pin Variables**************

//IR Sensors on PARKING SLOT
int IR1=10;
int IR2=11;
int IR3=12;

//IR Sensors on GATE
int IRgateEntry=7;
int IRgateExit=8;

//Servo Pin
 int servoPin=9;

//**************Global Variables***************
int pos = 0;                // variable to store the servo position

int slotStatus1;            // variables to store  
int slotStatus2;            // parking slots 
int slotStatus3;            // status  

int i;


// Declare global variables which will be uploaded to server



//String sendval, sendval2, sendval3, postData;


void setup() {

// Declaring Pin type as INPUT  

  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 

  lcd.print("IOT Car Parking");
  delay(2000);
  lcd.setCursor(4,1);
  lcd.print("System ");
  delay(2000);
  lcd.clear();  
  

  myservo.attach(servoPin);  

  pinMode (IR1, INPUT);
  pinMode (IR2, INPUT);
  pinMode (IR3, INPUT);

  pinMode (IRgateEntry, INPUT);
  pinMode (IRgateExit, INPUT);  

  Serial.begin(9600); 
  Serial.println("Communication Started \n\n"); 
     
}

void loop() {   

// Openning Entry if any vahicle at the gate 


if(digitalRead(IRgateEntry)==0||digitalRead(IRgateExit)==0)
  {
    if((slotStatus1+slotStatus2+slotStatus3)!=3){
      OpenGate();      
  }
else
  {
      Serial.println("***************       ALL Parking Slots are BOOKED      *****************");
      Serial.println("-----   !!!!!!!!!!!!!!!   ENTRY RESTRICTED  !!!!!!!!!!!  "); 
           
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ALL SLOTS BOOKED");
      delay(2000);
      lcd.clear();
  }
    
}

// *********Checking Parkig Slot Status**********

  CheckSlotStatus();


lcd.setCursor(0,0);
lcd.print(" 1 - - 2 - - 3  ");
lcd.setCursor(1,1);
lcd.print(slotStatus1);
lcd.setCursor(7,1);
lcd.print(slotStatus2);
lcd.setCursor(13,1);
lcd.print(slotStatus3);

}



//*********************** User Defined Functions ***********************

void OpenGate(){
  // Gate Openning
  
  //  Code for LCD
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("DOOR OPENING");

  Serial.println("Door Openning........");     
  
  //Code for Servo rotating 0 to 180 degree

     for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                                         // in steps of 1 degree
         myservo.write(pos);            // tell servo to go to position in variable 'pos'
         delay(15);                       
     }
  Serial.println("***** PLEASE ENTER/EXIT *****");
     
      delay(2000);
     
  
  // Gate Closing
  
  //  Code for LCD 
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("DOOR CLOSING");
      delay(1000);
  
  
//Code for Servo rotating 180 to 0 degree  
Serial.println("Door Closing"); 
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                      // waits 15 ms for the servo to reach the position
      }
      lcd.clear();
}


void CheckSlotStatus(){
  if(digitalRead(IR1)==0){
        Serial.print("Parking Slot 1-> BOOK  ");
        slotStatus1=1;
        
  }
else { 
        Serial.print("Parking Slot 1-> FREE ");
        slotStatus1=0;
}

if(digitalRead(IR2)==0){
        Serial.print("  Slot 2-> BOOK ");
        slotStatus2=1;
        
}
else { 
        Serial.print("  Slot 2-> FREE ");
        slotStatus2=0;
}

if(digitalRead(IR3)==0){
        Serial.println("  Slot 3-> BOOK");
        slotStatus3=1;        
}
else { 
        Serial.println("  Slot 3-> FREE");
        slotStatus3=0;
}

}
