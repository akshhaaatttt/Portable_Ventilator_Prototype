#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

int potpin = 0;
int val;
float pos = 0;

void setup() {
    lcd.init();
    lcd.backlight();
    myservo.attach(9);
    Serial.begin(115200);
    lcd.setCursor(0, 0);
    lcd.print("Emergency Vent");
    lcd.setCursor(2, 1);
    lcd.print("The Seviours");
    delay(4000);
}

void loop() {
    val = analogRead(potpin);
    val = map(val, 0, 1023, 0, 180);
    myservo.write(val);
    Serial.println(val);
    delay(15);

    if (val <= 30) {
        lcd.setCursor(0, 0);
        lcd.print("Spd:Fast Ang:100  ");
        lcd.setCursor(0, 1);
        lcd.print("Breath cycle 2.5 sec ");
        for (pos = 0; pos <= 100; pos += 1) {
            myservo.write(pos);
            delay(15);
        }
        for (pos = 100; pos >= 0; pos -= 1) {
            myservo.write(pos);
            delay(15);
        }
    } else if (val >= 31 && val <= 60) {
        lcd.setCursor(0, 0);
        lcd.print("Spd:Fast Ang:110   ");
        lcd.setCursor(0, 1);
        lcd.print("Breath cycle 3 sec ");
        for (pos = 0; pos <= 110; pos += 1) {
            myservo.write(pos);
            delay(15);
        }
        for (pos = 110; pos >= 0; pos -= 1) {
            myservo.write(pos);
            delay(15);
        }
    } else if (val >= 61 && val <= 90) {
        lcd.setCursor(0, 0);
        lcd.print("Spd:Fast Ang:120  ");
        lcd.setCursor(0, 1);
        lcd.print("Breath cycle 3.53 sec ");
        for (pos = 0; pos <= 120; pos += 1) {
            myservo.write(pos);
            delay(15);
        }
        for (pos = 120; pos >= 0; pos -= 1) {
            myservo.write(pos);
            delay(15);
        }
    } else if (val >= 91 && val <= 120) {
        lcd.setCursor(0, 0);
        lcd.print("Spd:Slow Ang:100  ");
        lcd.setCursor(0, 1);
        lcd.print("Breath cycle 5 sec ");
        for (pos = 0; pos <= 100; pos += 0.6) {
            myservo.write(pos);
            delay(15);
        }
        for (pos = 100; pos >= 0; pos -= 0.6) {
            myservo.write(pos);
            delay(15);
        }
    } else if (val >= 121 && val <= 150) {
        lcd.setCursor(0, 0);
        lcd.print("Spd:Slow Ang:110  ");
        lcd.setCursor(0, 1);
        lcd.print("Breath cycle 5.5 sec ");
        for (pos = 0; pos <= 110; pos += 0.6) {
            myservo.write(pos);
            delay(15);
        }
        for (pos = 110; pos >= 0; pos -= 0.6) {
            myservo.write(pos);
            delay(15);
        }
    } else if (val >= 151 && val <= 180) {
        lcd.setCursor(0, 0);
        lcd.print("Spd:Slow Ang:120  ");
        lcd.setCursor(0, 1);
        lcd.print("Breath cycle 6 sec ");
        for (pos = 0; pos <= 120; pos += 0.6) {
            myservo.write(pos);
            delay(15);
        }
        for (pos = 120; pos >= 0; pos -= 0.6) {
            myservo.write(pos);
            delay(15);
        }
    }
}
