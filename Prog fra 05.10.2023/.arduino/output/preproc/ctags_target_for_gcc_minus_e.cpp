# 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino"
# 2 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 05.10.2023\\SG90\\SG90.ino" 2
Servo myServoVert;
Servo myServoHori;






int mestLys;
uint32_t sensorListe[] = {A0, A1, A2, A3};
uint32_t lysListe[] = {};

void setup()
{
    Serial.begin(9600);
    myServoVert.attach(4, -270, 270);
    myServoHori.attach(2, -270, 270);
    for(int i=0; i<4; i++){
        pinMode(sensorListe[i], 0x0);
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
