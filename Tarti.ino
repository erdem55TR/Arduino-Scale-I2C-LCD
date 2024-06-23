
#include "HX711.h"
#include <LiquidCrystal_I2C.h> // Kütüphanemizi ekliyoruz
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DOUT 3
#define CLK 2
HX711 scale(DOUT, CLK);
float kalibrasyon_faktoru = 389.5; 
float deger ;
void setup() {
 
Serial.begin(9600); // İletişim hızı belirlenir: Saniyede 9600 bit olarak belirlendi
  lcd.begin();     
scale.set_scale(kalibrasyon_faktoru); // Ölçek ayarlandı
scale.tare(); // Ölçek sıfırlandı
  
}
void loop() { 
  
  scale.set_scale(kalibrasyon_faktoru); 
   if(scale.get_units() >1 ){
    deger = scale.get_units();
    } else {
    deger = 0;
    }
   lcd.clear();                 
   lcd.setCursor(1, 0);         
   lcd.print("Erdem Murathan");
   lcd.setCursor(1, 1);         
   lcd.print("GRAM ==");

   lcd.print(deger);
   delay(300);
  
}
