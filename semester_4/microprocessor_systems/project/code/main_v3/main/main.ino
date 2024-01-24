#define IN_1  D8          // L298N in1 motors Rightx          GPIO15(D8)
#define IN_2  D7          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  D4           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  D3           // L298N in4 motors Left            GPIO0(D3)

#define TRIG D5
#define ECHO D6

#define LT1 D2
#define LT2 D1

#define LT_SIGNAL D0

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* data received from application */
String  data = "";

int speedCar = 400;         // 400 - 1023.
int speed_Coeff = 3;

long duration;
int distance;

/* define port */
ESP8266WebServer server(80);
 
/* WIFI settings */
const char* ssid = "Car";

void setup() {
 Serial.begin(115200);
 pinMode(TRIG, OUTPUT);
 pinMode(ECHO, INPUT);
// pinMode(ENA, OUTPUT);
// pinMode(ENB, OUTPUT);
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT);
 
 pinMode(LT1, INPUT); 
 pinMode(LT2, INPUT); 
 
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);
//
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void goBack(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
  }

void goAhead(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
  }

void goRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
  }

void goLeft(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
 }

void lineTracker(){  
      digitalWrite(LT_SIGNAL, HIGH);
      //line detected by both
      if(digitalRead(LT1)==0 && digitalRead(LT2)==0){
        //Forward
        goAhead();
      }
      //line detected by left sensor
      else if(digitalRead(LT1)==0 && !digitalRead(LT2)==0){
        //turn left
        goLeft();    
      }
      //line detected by right sensor
      else if(!digitalRead(LT1)==0 && digitalRead(LT2)==0){
        //turn right
        goRight();
      }
      //line detected by none
      else if(!digitalRead(LT1)==0 && !digitalRead(LT2)==0){
        //stop
        stopRobot();
      }
      digitalWrite(LT_SIGNAL, LOW);
 }

 void objectAvoid(){
      digitalWrite(TRIG, LOW);
      delayMicroseconds(2);
      
      digitalWrite(TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG, LOW);
      
      duration = pulseIn(ECHO, HIGH);
      distance = duration * 0.034 / 2;
      Serial.print(distance);
      
      if (distance <= 15){
        stopRobot();
        delay(500);
        goLeft();
        delay(500);
      }
      else {
        goAhead();
      }
 }
 
 void loop()
{
  /* If the server available, run the "checkClient" function */
  server.handleClient();
  data = server.arg("State");
 
  if (data == "up") goAhead();
  else if (data == "down") goBack();
  else if (data == "left") goLeft();
  else if (data == "right") goRight();
  else if (data == "stop") stopRobot();  

  else if (data == "linetracker") lineTracker();
  else if (data == "objectavoid") objectAvoid();
  else stopRobot();
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
