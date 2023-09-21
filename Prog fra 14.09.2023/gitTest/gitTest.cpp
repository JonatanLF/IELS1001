
//Første bokstav er vokal: 1:0, 2:22, 3:2, 4:21, 5:15, 6:9
//Første bokstav er konsonant: 1:0, 2:24, 3:16, 4:22, 5:6, 6:12

#include <iostream.h>


String innTekst;
String alfabet[] = 
{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", 
"o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void setup()
{
    Serial.begin(9600);
}


void tekstInn()
{
    std::cin >> innTekst;
}

void skriv()
{
    
}

void loop()
{
    skriv();
}