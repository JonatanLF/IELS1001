#define sensor A5
#define led 7

int snittMaling;
int sammenlagt = 0;
unsigned long currTime;
unsigned long prevTime = 0;
int ledState = LOW;
uint32_t sensorListe[] = {0, 0, 0, 0, 0};

void setup()
{
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
}

int sensorSnitt()
{
    for(int i = 0; i < 5; i++){
        sammenlagt -= sensorListe[i];
        sensorListe[i] = analogRead(sensor);
        sammenlagt += sensorListe[i];
    }
    return snittMaling = sammenlagt / 5;
}

void lys()
{
    int hastighet = map(sensorSnitt(), 0, 1023, 100, 1500);
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