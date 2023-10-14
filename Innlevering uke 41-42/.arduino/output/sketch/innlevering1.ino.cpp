#include <Arduino.h>
#line 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering1\\innlevering1.ino"
#define sensor A5
#define led 7

int snittMaling;
unsigned long currTime;
unsigned long prevTime = 0;
int ledState = LOW;

#line 9 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering1\\innlevering1.ino"
void setup();
#line 16 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering1\\innlevering1.ino"
int sensorSnitt();
#line 26 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering1\\innlevering1.ino"
void lys();
#line 37 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering1\\innlevering1.ino"
void loop();
#line 9 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering1\\innlevering1.ino"
void setup()
{
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
}

int sensorSnitt()
{
    snittMaling = 0;
    int sammenlagt = 0;
    for(int i = 0; i < 5; i++){
        sammenlagt += analogRead(sensor);
    }
    return snittMaling = sammenlagt / 5;
}

void lys()
{
    int hastighet = map(sensorSnitt(), 0, 900, 100, 1500);
    currTime = millis();
    if(currTime - prevTime >= hastighet){
        ledState = !ledState;
        prevTime = currTime;
    }
    digitalWrite(led, ledState);
}

void loop()
{
    lys();
}
