/*
 *  Taloselectronics
 *  soporte@taloselectronics.com 
 *  Rafael Lozano Rolón
*/
#include<LiquidCrystal_I2C.h>

#define sensor_pin 2
LiquidCrystal_I2C lcd (0x27,20,4);

void setup()
{
    pinMode(sensor_pin, INPUT_PULLUP);
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0,0);
    lcd.print("Bienvenido");

    delay(500);

    lcd.clear();    
}
void loop()
{
    bool state = digitalRead(sensor_pin);
    int flama = analogRead(A0);
    flama = map(flama,0,1023,100,0);
    lcd.setCursor(2,1);
    lcd.print("sensor de flama");
    lcd.setCursor(2,2);
    lcd.print("Porcentaje:");
    lcd.print(flama);
    lcd.print("%  ");
    if(flama > 90)
    {
        lcd.clear();
        lcd.setCursor(6,1);
        lcd.print("ALERTA!");
        lcd.setCursor(2,2);
        lcd.print("FLAMA DETECTADA");
        delay(1000);
        lcd.clear();
    }

}