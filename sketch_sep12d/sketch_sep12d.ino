#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[]   = "CE-ESL";
char pass[]   = "ceeslonly";
char server[] = "blynk.celab.network";
char auth[]   = "6DkD15dgzvf_sbo801iHkw5hXNaP_AaA";

BLYNK_WRITE(V5)
{
  // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
  // this method will be triggered every day
  // until you remove widget or stop project or
  // clean stop/start fields of widget
  Serial.print("Got a value: ");
  Serial.println(param.asInt());
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,server,8080);
  pinMode(A6,INPUT);
}

void loop()
{
  //readPoten();
  Blynk.run();
}
/*void readPoten(){
  int val = analogRead(A6
  );
   Blynk.virtualWrite(V0,val);
   Serial.println(val);
   delay(200);
}*/
