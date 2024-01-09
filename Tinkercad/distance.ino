#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32, 16, 2); // Format -> (Address,Width,Height )

#define echoPin 2 // attach pin D2 Arduino to Echo pin of Sensor module
#define trigPin 3 // attach pin D3 Arduino to Trig pin of Sensor module

long duration; // Declare variable to store echo time duration

int distance; // Declare variable to store the result (distance)

void setup()
{
    lcd.init();      // initialize the lcd
    lcd.backlight(); // Turn on the Backlight

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT

    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

    // Serial Communication is starting with 9600 of baudrate speed
    Serial.begin(9600);

    // The text to be printed in serial monitor
    Serial.println("Distance measurement using Arduino Uno");

    delay(1000);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.0344 / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    lcd.clear();         // Clear the display buffer
    lcd.setCursor(0, 0); // Set cursor for "Distance:" (Column, Row)

    lcd.print("Distance:"); // print "Distance:" at (0, 0)
    lcd.setCursor(0, 1);    // Set cursor for output value (0, 1)

    lcd.print(distance); // print Output in cm at (0, 1)
    lcd.setCursor(4, 1); // move cursor to (4, 1)
    lcd.print("cm");     // print "cm" at (4, 1)

    delay(1000);
}
