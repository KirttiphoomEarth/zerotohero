#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[]   = "CE-ESL";
char pass[]   = "ceeslonly";
char server[] = "blynk.celab.network";
char auth[]   = "6DkD15dgzvf_sbo801iHkw5hXNaP_AaA";
/*BLYNK_WRITE(V5)
{
  Serial.print("Got a value: ");
  Serial.println(param.asStr());
  int num = param.asInt();
}*/
//int num2;
long timer = millis();

// code by P'Boy
uint8_t led1 = 12;
int PWM_LED1;

BLYNK_WRITE(V4)
{
  Serial.print("Got a value: ");
  Serial.println(param.asStr());
//  int num2 = param.asInt();
  PWM_LED1 = param.asInt();

if(millis() - timer >= 300){

 // code by P'Boy
    ledcWrite(1, PWM_LED1);
    timer = millis();
  }
}

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass,server,8080);

// code by P'Boy
    ledcAttachPin(led1, 1);
    ledcSetup(1, 12000, 12);
}

void loop()
{
  Blynk.run();
}
