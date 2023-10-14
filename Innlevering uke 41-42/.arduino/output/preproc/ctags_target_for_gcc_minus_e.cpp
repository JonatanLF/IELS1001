# 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering2\\innlevering2.ino"
/*Under setter jeg hvilke pins koden skal bruke og gir hvert pin et nytt navn tilsvarende funksjonen den har*/




/*Deretter oppretter jeg variabler som skal brukes i koden samt gir de riktig variabeltype*/
unsigned long currTime;
unsigned long prevTime = 0;
unsigned long gulTime;
unsigned long gulTimeLast = 0;
int intervall = 1000;
bool gulState = false;
int lysVekselState = 0x0;
/*I setup starter jeg Serial slik at jeg kan printe ting ut på skjermen for testing og fiksing av koden.

Deretter bestemmer jeg om de forskjellige komponentene som er tilkoblet arduino-pinsene skal gi oss INPUT eller

OUTPUT.*/
# 17 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering2\\innlevering2.ino"
void setup()
{
    Serial.begin(9600);
    pinMode(13, 0x1);
    pinMode(11, 0x1);
    pinMode(12, 0x1);
    pinMode(2, 0x0);
}
/*Her har jeg funksjonen til knappen. Den endrer på en variabel "lysVekselState" for hver gang

den trykkes, mellom LOW og HIGH. Dette vil vi se senere gjør slik at grønn og rød bytter på å

lyse for hver gang knappen trykkes. I tillegg leser vi av hvor lenge knappen holdes inne i millis.

Dersom knappen holdes inne i mer enn 1,5 sekunder vil vi ikke endre på "lysVekselState", men variabelen

"intervall" istedenfor. Dette bryter litt med oppgaven som sa at vi ikke skulle gjøre noe med det gule

lyset, men jeg ønsket at knappen skulle kunne endre forskjellige lys. For å oppnå dette oppdaterer "prevTime"

seg til millis konstant når knappen ikke blir rørt. I tillegg oppdaterer "currTime" seg til millis så lenge

knappen holdes inne. Dette betyr at "currTime" - "prevTime" tilsvarer tiden knappen har blitt holdt inne.*/
# 33 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering2\\innlevering2.ino"
void knapp()
{
    int buttonState = digitalRead(2);
    if(buttonState == 0x1){
        currTime = millis();
    }
    if((buttonState == 0x0) && (currTime >= 50 + prevTime)){
        if(currTime - prevTime > 1500){
            intervall -= 400;
            if(intervall == -200){
                intervall = 1000;
            }
        }
        else{
            lysVekselState = !lysVekselState;
        }
        prevTime = currTime;
    }
    else if(buttonState == 0x0){
        prevTime = millis();
    }
}
/*Denne koden bruker millis til å bytte mellom at LED er av og på i et tidsintervall.*/
void gulLys()
{
    digitalWrite(12, gulState);
    gulTime = millis();
    if(gulTime-gulTimeLast >= intervall){
        gulState = !gulState;
        gulTimeLast = gulTime;
    }
}
/*Dette er koden som bestemmer om Rødt eller grønt lys er av eller på. Denne koden kunne blitt skrevet

inni knapp-koden, men jeg personlig liker å skille de to.*/
# 67 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Innlevering uke 41-42\\innlevering2\\innlevering2.ino"
void andreLys()
{
    digitalWrite(13, lysVekselState);
    digitalWrite(11, !lysVekselState);
}
/*loop som består av funksjonene fra tidligere i koden, og kun de funksjonene.*/
void loop()
{
    knapp();
    gulLys();
    andreLys();
}
