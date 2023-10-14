#define sensor A5
#define led 7

int snittMaling;
unsigned long currTime;
unsigned long prevTime = 0;
int ledState = LOW;

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