#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte robotA[8] = { B01110, B11111, B10101, B11111, B01110, B01110, B10001, B00000 };
byte robotB[8] = { B11111, B10101, B11111, B11111, B01110, B01010, B11011, B00000 };
byte dataPacket[8] = { B00000, B00100, B01110, B11111, B01110, B00100, B00000, B00000 };
byte checkMark[8] = { B00000, B00001, B00011, B10110, B11100, B01000, B00000, B00000 };
byte crossMark[8] = { B00000, B10001, B01010, B00100, B01010, B10001, B00000, B00000 };

int tusOku() {
  int adcDegeri = analogRead(0);
  if (adcDegeri > 1000) return 0; 
  if (adcDegeri < 50)   return 2; 
  if (adcDegeri < 250)  return 3; 
  if (adcDegeri < 450)  return 4; 
  if (adcDegeri < 650)  return 1; 
  if (adcDegeri < 850)  return 5; 
  return 0;
}

void daktiloYaz(String metin, int satir, int baslangic, int hiz) {
  lcd.setCursor(baslangic, satir);
  for(int i = 0; i < metin.length(); i++) {
    lcd.print(metin[i]);
    delay(hiz);
  }
}

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, robotA);
  lcd.createChar(1, robotB);
  lcd.createChar(2, dataPacket);
  lcd.createChar(3, checkMark);
  lcd.createChar(4, crossMark);
}

void loop() {
  lcd.clear();
  delay(500);
  daktiloYaz("Sistem Basliyor.", 0, 0, 50);
  daktiloYaz("Lutfen Bekleyin", 1, 0, 50);
  delay(1500);

  lcd.clear();
  for(int i = 0; i <= 6; i++) {
    int y = i, z = 15 - i;
    if(i > 0) {
      lcd.setCursor(y - 1, 1); lcd.print(" ");
      lcd.setCursor(z + 1, 1); lcd.print(" ");
    }
    lcd.setCursor(y, 1); lcd.write(byte(0));
    lcd.setCursor(z, 1); lcd.write(byte(1));
    delay(300); 
  }

  lcd.setCursor(7, 1); lcd.write(byte(2));
  delay(1500);

  bool kararVerildi = false;

  while(!kararVerildi) {
    lcd.clear();
    lcd.setCursor(0, 0);  lcd.print("<- TESTI BASLAT");
    lcd.setCursor(8, 1);  lcd.print("IPTAL ->");

    bool tusaBasildi = false;
    while(!tusaBasildi) {
      int basilanTus = tusOku();
      
      if(basilanTus == 1) { 
        tusaBasildi = true;
        kararVerildi = true; 
        
        for(int b = 0; b < 3; b++){ lcd.noDisplay(); delay(150); lcd.display(); delay(150); }
        
        lcd.clear();
        lcd.setCursor(2, 0); lcd.print("Test Basarili!");
        lcd.setCursor(7, 1); lcd.write(byte(3)); 
        delay(3000);
      }
      else if(basilanTus == 2) { 
        tusaBasildi = true;
        kararVerildi = true;
        
        lcd.clear();
        lcd.setCursor(2, 0); lcd.print("Islem Iptal.");
        lcd.setCursor(7, 1); lcd.write(byte(4)); 
        delay(3000);
      }
    }
  }
}
