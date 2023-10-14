# 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering2\\innlevering2.ino"



int snittMaling;
int sammenlagt = 0;
unsigned long currTime;
unsigned long prevTime = 0;
int ledState = 0x0;
uint32_t sensorListe[] = {0, 0, 0, 0, 0};

void setup()
{
    Serial.begin(9600);
    pinMode(A5, 0x0);
    pinMode(7, 0x1);
}

int sensorSnitt()
{
    for(int i = 0; i < 5; i++){
        sammenlagt -= sensorListe[i];
        sensorListe[i] = analogRead(A5);
        sammenlagt += sensorListe[i];
    }
    return snittMaling = sammenlagt / 5;
}

void lys()
{
    int hastighet = map(sensorSnitt(), 0, 900, 100, 1500);
    currTime = millis();
    Serial.println(hastighet);
    if(currTime - prevTime >= hastighet){
        ledState = !ledState;
        prevTime = currTime;
    }
    digitalWrite(7, ledState);
}

void loop()
{
    lys();
}
