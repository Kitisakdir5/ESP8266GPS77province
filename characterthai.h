#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);
byte customChar1[8] = { // โ
  B00001,
  B11110,
  B10000,
  B01110,
  B00010,
  B00010,
  B00011,
  B00011
};
byte customChar2[8] = { // ป 
  B00001,
  B00001,
  B11001,
  B11001,
  B01001,
  B01001,
  B01001,
  B01111
};
byte customChar3[8] = { // ร
  B00000,
  B00001,
  B11110,
  B11100,
  B00100,
  B00100,
  B01100,
  B01100
};
byte customChar4[8] = { // ด
  B00000,
  B00000,
  B01110,
  B10001,
  B11101,
  B10101,
  B10101,
  B01001
};
byte customChar5[8] = { // อ
  B00000,
  B00000,
  B11110,
  B00001,
  B11101,
  B10001,
  B10001,
  B11110
};
byte customChar6[8] = { // ก
  B00000,
  B00000,
  B01111,
  B10001,
  B01101,
  B10001,
  B10001,
  B10001
};
byte customChar7[8] = { // สระอำ
  B11000,
  B11000,
  B00011,
  B00101,
  B00001,
  B00001,
  B00001,
  B00001
};
byte customChar8[8] = { // ล
  B00000,
  B00000,
  B11111,
  B00001,
  B01101,
  B10011,
  B11001,
  B11001
};

byte customChar19[8] = { // สระแอ
  B00000,
  B00000,
  B10010,
  B10010,
  B10010,
  B10010,
  B11011,
  B11011
};

byte customChar24[8] = { // พ 
  B00000,
  B00000,
  B10001,
  B10101,
  B10101,
  B11111,
  B10101,
  B10101
};
byte customChar25[8] = { // ม
  B00000,
  B00000,
  B11001,
  B01001,
  B01001,
  B01001,
  B11111,
  B11001
};

byte customChar31[8] = { // ข
  B00000,
  B00000,
  B11101,
  B11101,
  B00101,
  B01001,
  B01001,
  B00110
};
byte customChar32[8] = { // ย
  B00000,
  B00000,
  B11001,
  B10001,
  B01101,
  B10001,
  B10001,
  B01110
};
byte customChar33[8] = { // ว
  B00000,
  B00000,
  B01110,
  B10001,
  B00001,
  B00001,
  B00011,
  B00011
};

byte customChar34[8] = { // ร กับ ไม่โท
  B01010,
  B01100,
  B00001,
  B11110,
  B11000,
  B00100,
  B01100,
  B01100
};

byte customChar35[8] = { // ล กับ ไม้โท
  B00101,
  B00110,
  B00000,
  B01111,
  B00001,
  B01111,
  B01001,
  B01101
};

byte customChar36[8] = { // ถ
  B00000,
  B00000,
  B00000,
  B01111,
  B11001,
  B01001,
  B01101,
  B01101
};
byte customChar37[8] = { // ถู
  B00000,
  B01111,
  B10001,
  B01001,
  B10001,
  B11000,
  B00011,
  B00011
};

void waitwifigps() {
	lcd.backlight();
	lcd.createChar(1, customChar1);
	lcd.createChar(2, customChar2);
	lcd.createChar(3, customChar3);
	lcd.createChar(4, customChar4);
	lcd.createChar(5, customChar5);
	lcd.createChar(6, customChar6);
	lcd.createChar(7, customChar7);
	lcd.createChar(8, customChar8);
	lcd.home();

	lcd.setCursor(6, 1);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(3);
  lcd.write(5);
  lcd.print("...");
	lcd.setCursor(4, 2);
  lcd.print("WIFI and GPS");
}

void gpsready() {
	lcd.createChar(1, customChar24);
	lcd.createChar(2, customChar34);
	lcd.createChar(3, customChar5);
	lcd.createChar(4, customChar25);
	lcd.createChar(5, customChar19);
	lcd.createChar(6, customChar35);
	lcd.createChar(7, customChar33);
	lcd.home();
	lcd.setCursor(2, 1);
  lcd.print("GPS") ;
  lcd.setCursor(6, 1);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  lcd.print("...");
	lcd.setCursor(2, 2);
  lcd.print("PUSH GREEN BUTTON") ;
}

void caution1() {
	lcd.createChar(1, customChar3);
	lcd.createChar(2, customChar36);
	lcd.createChar(3, customChar37);
	lcd.createChar(4, customChar6);
	lcd.createChar(5, customChar31);
	lcd.createChar(6, customChar1);
	lcd.createChar(7, customChar25);
  lcd.createChar(8, customChar32);
	lcd.home();
	lcd.setCursor(6, 0);
  lcd.print("CAUTION") ;
  lcd.setCursor(6, 2);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  lcd.write(8);
}


