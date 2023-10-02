#line 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"

#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_CLK 2
#define OLED_MOSI 3
#define OLED_RESET 4
#define OLED_DC 5
#define OLED_CS 6

#define LYS_MAAL A5

int sensorVerdi;
int spenning;

U8G2_UC1701_EA_DOGS102_1_4W_SW_SPI u8g2(U8G2_R0, OLED_CLK, OLED_MOSI, OLED_CS, OLED_DC, OLED_RESET);

#line 22 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"
void setup();
#line 29 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"
void lesDist();
#line 35 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"
void testWrite();
#line 46 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"
void loop();
#line 22 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"
void setup()
{
    Serial.begin(9600);
    u8g2.begin();
    pinMode(LYS_MAAL, INPUT);
}

void lesDist()
{
    sensorVerdi = analogRead(LYS_MAAL);
    spenning = sensorVerdi * 3.3 / 1023;
}

void testWrite() {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    //u8g2.drawUTF8(0,20, "spenning"); - Dersom man skal printe str funker dette
    u8g2.setCursor(0, 30);
    u8g2.print(spenning);
  } while ( u8g2.nextPage() );
  delay(1000);
}

void loop()
{
    //lesDist();
    testWrite();
}
