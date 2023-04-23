#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

 int irPin=12;  
 int buzz=11;  
 int count=0;  
 boolean state = true;  
 void setup()  
 {  
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
    lcd.backlight();  
  pinMode(irPin, INPUT);  
   pinMode(buzz, OUTPUT);  
  lcd.setCursor(0,0);  
  lcd.print("Count No : ");  
 }  
 void loop()  
 {  
  if (!digitalRead(irPin) && state){  
    count++;  
    state = false;  
    Serial.print("Count: ");  
    Serial.println(count);  
    lcd.setCursor(12,0);  
    lcd.print(count); 
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW); 
    delay(100); 
    
  }  
  if (digitalRead(irPin))  
  {  
    state = true;  
    delay(100);  
  }  }  
