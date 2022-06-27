/*
Project Name: IOT based smart vahicle parking system

Mirzana Jannat Piya
Roll 1704018

*/ 


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


#define HOST "iotcarparking1704018.000webhostapp.com"         //HOST URL without "http:// "  and "/" at the end of URL


#define WIFI_SSID "V2026"                                     // WIFI SSID here                                   
#define WIFI_PASSWORD "12345678"                              // WIFI password here


//************** Pin Variables**************

//IR Sensors on PARKING SLOT

int IR1=D5;
int IR2=D6;
int IR3=D7;

int LED=D4;


//**************Global Variables***************


int slotStatus1=1,slotStatus2=1,slotStatus3=1;            // variables to store parking slots status


int i;

// Declare global variables which will be uploaded to server
String sendval, sendval2, sendval3, postData;


void setup() {

  pinMode (LED, OUTPUT);


     
Serial.begin(115200); 
Serial.println("Communication Started \n\n");  
delay(1000);
  


WiFi.mode(WIFI_STA);           
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             //try to connect with wifi
Serial.print("Connecting to ");


Serial.print(WIFI_SSID);

while (WiFi.status() != WL_CONNECTED) 
{ Serial.print(".");

    delay(500); }

digitalWrite(LED, HIGH);

Serial.println();
Serial.print("Connected to ");
Serial.println(WIFI_SSID);
Serial.print("IP Address is : ");
Serial.println(WiFi.localIP());                   //print local IP address to serial monitor

delay(30);

// Declaring Pin type as INPUT  

  pinMode (IR1, INPUT);
  pinMode (IR2, INPUT);
  pinMode (IR3, INPUT);
}



void loop() { 


WiFiClient client;
HTTPClient http;                // http object of class HTTPClient




// *********Checking Parkig Slot Status**********

  CheckSlotStatus();



//************ POST data to Server*******************

// Convert integer variables to string

sendval = String(slotStatus1+1);  
sendval2 = String(slotStatus2+1); 
sendval3 = String(slotStatus3+1);   



//Creating POST request url 
// We can post values to PHP files as  example.com/dbwrite.php?name1=val1&name2=val2&name3=val3
postData = "sendval=" + sendval + "&sendval2=" + sendval2+ "&sendval3=" + sendval3;


// Update Host URL here:-    
http.begin(client,"http://iotcarparking1704018.000webhostapp.com/dbwritephp.php");              // Connect to host where MySQL databse is hosted
http.addHeader("Content-Type", "application/x-www-form-urlencoded");                            //Specify content-type header

  
 
int httpCode = http.POST(postData); 
Serial.print(postData);  // Send POST request to php file and store server response code in variable named httpCode
Serial.println("Values are, sendval = " + sendval + "sendval2 = "+sendval2+ "sendval3 = "+sendval3 );


// if connection eatablished then do this
if (httpCode == 200) { Serial.println("Values uploaded successfully."); 
  Serial.println(httpCode); 
  String webpage = http.getString();    // Get html webpage output and store it in a string
  Serial.println(webpage + "\n"); 
}



// if failed to connect then return and restart
else { 
  Serial.println(httpCode); 
  Serial.println("Failed to upload values. \n"); 
  http.end(); 
  return; }


delay(1000); 
digitalWrite(LED_BUILTIN, LOW);
delay(1000);
digitalWrite(LED_BUILTIN, HIGH);



http.end();


}



//*********************** User Defined Functions ***********************


void CheckSlotStatus(){
  if(digitalRead(IR1)==0){
        Serial.println("Parking Slot 1-> BOOK");
        slotStatus1=1;
        
}
else { 
        Serial.println("Parking Slot 1-> FREE");
        slotStatus1=0;
}

if(digitalRead(IR2)==0){
        Serial.println("Parking Slot 2-> BOOK");
        slotStatus2=1;
        
}
else { 
        Serial.println("Parking Slot 2-> FREE");
        slotStatus2=0;
}

if(digitalRead(IR3)==0){
        Serial.println("Parking Slot 3-> BOOK");
        slotStatus3=1;        
}
else { 
        Serial.println("Parking Slot 3-> FREE");
        slotStatus3=0;
}

}


