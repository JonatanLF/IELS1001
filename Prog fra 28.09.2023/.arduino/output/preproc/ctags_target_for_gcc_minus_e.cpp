# 1 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"

# 3 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino" 2
# 4 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino" 2
# 5 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino" 2
# 17 "C:\\Users\\jonat\\OneDrive\\Dokumenter\\!VisualStudioCode\\Prog fra 28.09.2023\\øvingProg\\øvingProg.ino"
int sensorVerdi;
int spenning;

U8G2_UC1701_EA_DOGS102_1_4W_SW_SPI u8g2((&u8g2_cb_r0), 2, 3, 6, 5, 4);

void setup()
{
    Serial.begin(9600);
    u8g2.begin();
    pinMode(A5, 0x0);
}

void lesDist()
{
    sensorVerdi = analogRead(A5);
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
