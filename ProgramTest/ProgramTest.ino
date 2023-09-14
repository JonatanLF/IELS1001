
#define lysDiode 8

void setup()
{
    Serial.begin(9600);
    pinMode(lysDiode, OUTPUT);
}

void lys()
{
    digitalWrite(lysDiode, HIGH);
}

void loop()
{
    lys();
    delay(250);
}