#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[]   = "CE-ESL";
char pass[]   = "ceeslonly";
char server[] = "blynk.celab.network";
char auth[]   = "6DkD15dgzvf_sbo801iHkw5hXNaP_AaA";
int num;
int timer;
 BLYNK_WRITE(V5)
{
  Serial.print("Got a value: ");
  Serial.println(param.asStr());
  num = param.asInt();
}
void setup() {
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass,server,8080);
 timer = millis();
 pinMode(12,OUTPUT);

 }

void loop() {
  

  if(millis() - timer > 1000 && num >= 0 ) {
    Serial.print("TIME COUT : ");
    Serial.println(num);
     num--;
    timer = millis();
    if(num == 0){
      digitalWrite(12,1);
    }
  }
  Blynk.run();
   
 }
