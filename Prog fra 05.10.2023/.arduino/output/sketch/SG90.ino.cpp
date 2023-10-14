#include <Arduino.h>
#line 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino"
#include <Servo.h>
Servo myServoVert;
Servo myServoHori;

#define sensor1 A0
#define sensor2 A1
#define sensor3 A2
#define sensor4 A3

int mestLys;
uint32_t sensorListe[] = {sensor1, sensor2, sensor3, sensor4};
uint32_t lysListe[] = {};

#line 14 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino"
void setup();
#line 24 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino"
void sookLys();
#line 56 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino"
void loop();
#line 14 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino"
void setup()
{
    Serial.begin(9600);
    myServoVert.attach(4, -270, 270);
    myServoHori.attach(2, -270, 270);
    for(int i=0; i<4; i++){
        pinMode(sensorListe[i], INPUT);
    }
}

void sookLys()
{
    for(int i=0; i<4; i++){
        lysListe[i] = analogRead(sensorListe[i]);
    }
    int lastLys = 0;
    for(int i=0; i<4; i++){
        if(lysListe[i] > lastLys){
            lastLys = lysListe[i];
            mestLys = i;
        }
    }
    int currentVert = myServoVert.read();
    int currentHori = myServoHori.read();
    int rotVert = 1;
    int rotHori = 1;
    
    if(mestLys == 0){
        rotVert = -rotVert;
        rotHori = -rotHori;
    }
    else if(mestLys == 1){
        rotVert = -rotVert;
    }
    else if(mestLys == 3){
        rotHori = -rotHori;
    }

    myServoVert.write(currentVert + rotVert);
    myServoHori.write(currentHori + rotHori);
}

void loop()
{
    sookLys();
    delay(20);
}
