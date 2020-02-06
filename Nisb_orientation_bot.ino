
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

#include <Blynk.h>
#define BLYNK_PRINT Serial

#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int ledpin = 12; // M1
const int ledpin1 = 14; // M1
const int ledpin2 = 27; // M2
const int ledpin3 = 26; // M2

const int freq= 5000;

const int ledChannel=0; 
const int ledChannel1=1;
const int ledChannel2=2;
const int ledChannel3=3;

const int resolution= 8;

//int pos = 0; 

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "auth_code";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "password";

void setup() {  
  //myservo.attach(13);
  
 ledcSetup(ledChannel,freq,resolution);
 ledcAttachPin(ledpin,ledChannel);
 
 ledcSetup(ledChannel1,freq,resolution);
 ledcAttachPin(ledpin1,ledChannel1);
 
 ledcSetup(ledChannel2,freq,resolution);
 ledcAttachPin(ledpin2,ledChannel2);
 
 ledcSetup(ledChannel3,freq,resolution);
 ledcAttachPin(ledpin3,ledChannel3);
  pinMode(12, OUTPUT); 
  pinMode(14, OUTPUT); 
  pinMode(27, OUTPUT); 
  pinMode(26, OUTPUT); 
 // pinMode(2,OUTPUT);
  
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  

  Blynk.begin(auth, ssid, pass);
  //digitalWrite(V1,LOW);

}
BLYNK_WRITE(V1)
  {
    if (param.asInt()){       
         Serial.println("forward");
    ledcWrite(ledChannel,255);
    ledcWrite(ledChannel1,0);
    ledcWrite(ledChannel2,255);
    ledcWrite(ledChannel3,0);
    } else {
        ledcWrite(ledChannel,0);
    ledcWrite(ledChannel1,0);   
    ledcWrite(ledChannel2,0);
    ledcWrite(ledChannel3,0);
    }
}
BLYNK_WRITE(V2)
  {
    if (param.asInt()){       
         Serial.println("backward");
    ledcWrite(ledChannel,0);
    ledcWrite(ledChannel1,255);
    ledcWrite(ledChannel2,0);
    ledcWrite(ledChannel3,255);
    } else {
        ledcWrite(ledChannel,0);
    ledcWrite(ledChannel1,0);   
    ledcWrite(ledChannel2,0);
    ledcWrite(ledChannel3,0);
    }
}
BLYNK_WRITE(V3)
  {
    if (param.asInt()){       
         Serial.println("right");
    ledcWrite(ledChannel,177);
    ledcWrite(ledChannel1,0);
    ledcWrite(ledChannel2,255);
    ledcWrite(ledChannel3,0);
    } else {
        ledcWrite(ledChannel,0);
    ledcWrite(ledChannel1,0);   
    
    ledcWrite(ledChannel2,0);
    ledcWrite(ledChannel3,0);
    }
}
BLYNK_WRITE(V4)
  {
    if (param.asInt()){       
         Serial.println("left");
    ledcWrite(ledChannel,255);
    ledcWrite(ledChannel1,0);   
    ledcWrite(ledChannel2,177);
    ledcWrite(ledChannel3,0);
    } else {
        ledcWrite(ledChannel,0);
    ledcWrite(ledChannel1,0);   
    ledcWrite(ledChannel2,0);
    ledcWrite(ledChannel3,0);
    }
}


void loop(){   
 
  Blynk.run();
}
