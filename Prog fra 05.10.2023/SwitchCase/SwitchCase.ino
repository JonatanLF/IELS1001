#define redLED 2
#define greenLED 4
#define blueLED 7

bool red = LOW;
bool green = LOW;
bool blue = LOW;

void setup()
{
    Serial.begin(9600);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
}

void SC()
{
    int inn = Serial.read();
    switch(inn){
        case 'R':
      		red = !red;
            digitalWrite(redLED, red);
            break;
        case 'G':
      		green = !green;
            digitalWrite(greenLED, green);
            break;
        case 'B':
      		blue = !blue;
            digitalWrite(blueLED, blue);
            break;
      	case 'N':
      		digitalWrite(redLED, LOW);
      		digitalWrite(blueLED, LOW);
      		digitalWrite(greenLED, LOW);
      		break;
    }
}

void loop()
{
    SC();
}