#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int ldrPin = A0;  // analog pin to which LDR is connected
int ldrThreshold = 200;  // set the threshold for laser interruption
int ldrValue = 0;       // variable to store LDR values
const int buzzer = 9;

// Define constants for sensor pin and LED pin
const int sensorPin = A2;
const int ledPin = 10;

// Initialize the I2C LCD. The address (0x27 or 0x3F) and dimensions (16x2) might need to be adjusted
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);  // start the serial monitor
  lcd.init();          // initialize the LCD
  lcd.backlight();     // turn on the backlight
}

void loop() {
  ldrValue = analogRead(ldrPin);  // reads the LDR values
  Serial.println(ldrValue);       // prints the LDR values to the serial monitor
  delay(100);                     // wait

  if (ldrValue > ldrThreshold) {
    tone(buzzer, 1000); // Beep the buzzer
    lcd.clear();        // Clear previous message
    lcd.setCursor(0, 0);
    lcd.print("OBJECT DETECTED!");
    delay(1500);        // Display the message for 1.5 seconds
  } else {
    noTone(buzzer);
    lcd.clear();        // Optional: clear the message when the system is not triggered
  }

}