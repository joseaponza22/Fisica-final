#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int sensorPin = A0;
const int ledPin = 13;  // Pin de la placa para conectar la luz LED

int sensorValue = 0;
int percentValue = 0;

void setup() {                       
 lcd.init();
 lcd.backlight(); 
 lcd.setCursor(0,0);
 lcd.print("Bienvenido.......");
 delay(4000);
 lcd.clear();

 pinMode(ledPin, OUTPUT); // Configura el pin de la LED como salida
}

void loop() {
 
 sensorValue = analogRead(sensorPin);
 percentValue = map(sensorValue, 1023, 200, 0, 100);
 lcd.setCursor(0, 0);
 lcd.print(" ---HUMEDAD--- ");
 lcd.setCursor(7, 1);
    
 lcd.print(percentValue);
 lcd.print("%");

 if (percentValue > 60) {
   digitalWrite(ledPin, HIGH); // Enciende la luz LED si la humedad es superior al 60%
 } else {
   digitalWrite(ledPin, LOW); // Apaga la luz LED si la humedad no supera el 60%
 }

 delay(1000);
 lcd.clear();
}
