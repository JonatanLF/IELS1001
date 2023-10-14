/*
#define led 2
#define potMeter A0

int fadeAmount;
int brightness = 0;
int potVerdi;
int PN = 1;

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(potMeter, INPUT);
}

void lysEndring()
{
    potVerdi = analogRead(potMeter);
    fadeAmount = map(potVerdi, 0, 1023, 0, 10);
    brightness += fadeAmount * PN;
    analogWrite(led, brightness);
    if(brightness >= 255 || brightness <= 0){
        PN = -PN;
    }
    delay(50);
}

void loop()
{
    lysEndring();
}
*/
/*
#define led 2
#define knapp 3

unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned long newMillis;
int knappTeller = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(knapp, INPUT);
}

void knappFunk()
{
    if(digitalRead(knapp) == HIGH){
        currentMillis = millis();
    }
    else if((digitalRead(knapp) == LOW) && (currentMillis - previousMillis >= 50)){
        knappTeller += 1;
        Serial.print("Dette er knapp-trykk nr. ");
        Serial.println(knappTeller);
        Serial.print("Knappen ble holdt inne i ");
        Serial.print(currentMillis - newMillis);
        Serial.println(" millisekunder");
        if(currentMillis - newMillis <= 1000){
            Serial.println("dette var et kort trykk");
        }
        else{
            Serial.print("Dette var et langt trykk");
        }
        previousMillis = currentMillis;
    }
    else{
        newMillis = millis();
    }
}

void loop()
{
    knappFunk();
}
*/

#define calButton 4
#define sensor A0
#define lys 2

int minValue = 0;
int maxValue = 1023;
int sensorValue;
int newValue;

void setup()
{
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    pinMode(calButton, INPUT);
    pinMode(lys, OUTPUT);
}

void calibrate()
{
    if(digitalRead(calButton) == HIGH){
        maxValue = 0;
        minValue = 1023;
        unsigned long calTimePrev = millis();
        unsigned long calTime = millis()+1;
        while(calTime - calTimePrev <= 10000){
            calTime = millis();
            sensorValue = analogRead(sensor);
            if(sensorValue > maxValue){
                maxValue = sensorValue;
            }
            if(sensorValue < minValue){
                minValue = sensorValue;
            }
        }
    }
}

void light()
{
    sensorValue = analogRead(sensor);
    newValue = map(sensorValue, minValue, maxValue, 0, 255);
    analogWrite(lys, newValue);
}

void loop()
{
    calibrate();
    light();
}

/*
#define sensor A0

const int dataMengde = 10;
int data[dataMengde];
int dataIndex = 0;
int total = 0;
int snitt = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    for(int i = 0; i < dataMengde; i++){
        data[i] = 0;
    }
}

void utgjevning()
{
    total = total - data[dataIndex];
    data[dataIndex] = analogRead(sensor);
    total = total + data[dataIndex];
    dataIndex += 1;
    if(dataIndex >= dataMengde){
        dataIndex = 0;
    }
    snitt = total/dataMengde;
    Serial.println(snitt);
    delay(1);
}

void loop()
{
    utgjevning();
}
*/