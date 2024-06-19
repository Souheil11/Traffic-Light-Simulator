#include <TM1637Display.h>

// Define the TM1637 pins
const int CLK_PIN = 5;
const int DIO_PIN = 4;

// Create a TM1637Display object
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
    pinMode(14, OUTPUT); // Red LED connected to pin D5 on the board
    pinMode(12, OUTPUT); // Yellow LED connected to pin D6 on the board
    pinMode(13, OUTPUT); // Green LED connected to pin D7 on the board
    pinMode(15, OUTPUT); // Buzzer connected to pin D8 on the board

    // Initialize the TM1637 display
    display.setBrightness(7);
    display.clear();
}

// define the display countdown function
void countdown(int initialValue, int targetValue) {
    for (int i = initialValue; i >= targetValue; i--) {
        display.showNumberDec(i, true);
        delay(1000); // Delay for 1 second
    }
}

// Define function for green light behavior
void greenLight(int initialValue, int targetValue) {
    digitalWrite(13, HIGH);
    for (int i = initialValue; i >= targetValue; i--) {
        display.showNumberDec(i, true);
        greenLedSoundAlert();
    }
}

// Define function for blinking green light
void blinkGreenCountdown(int initialValue, int targetValue) {
    for (int i = initialValue; i >= targetValue; i--) {
        display.showNumberDec(i, true);
        greenLedBlink();
    }
}

// Define the sound Alert function of the green Light
void greenLedSoundAlert() {
    digitalWrite(15, HIGH);
    delay(100);
    digitalWrite(15, LOW);
    delay(400);
    digitalWrite(15, HIGH);
    delay(50);
    digitalWrite(15, LOW);
    delay(450);
}

// Define the greenLedBlink function with sound alert pattern
void greenLedBlink() {
    digitalWrite(15, HIGH);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(15, LOW);
    delay(100);
    digitalWrite(15, HIGH);
    delay(100);
    digitalWrite(15, LOW);
    delay(100);
    digitalWrite(15, HIGH);
    delay(100);
    digitalWrite(13, HIGH);
    digitalWrite(15, LOW);
    delay(100);
    digitalWrite(15, HIGH);
    delay(100);
    digitalWrite(15, LOW);
    delay(300);
    digitalWrite(13, LOW);
}

// define the display countdown function
void countdown(int initialValue) {
    for (int i = initialValue; i >= 1; i--) {
        display.showNumberDec(i, true); // Show the current number with leading zeros
        delay(1000); // Delay for 1 second
    }
    display.clear();
}

void loop() {
    // Red LED active for 5 seconds
    digitalWrite(14, HIGH);
    countdown(5, 1);

    // Yellow LED active for 3 seconds
    digitalWrite(12, HIGH);
    countdown(3, 1);

    // Deactivate Red and Yellow
    digitalWrite(14, LOW);
    digitalWrite(12, LOW);

    // Activate green light with bip sound and countdown
    greenLight(11, 4);

    // Green LED blinks 3 times with alert sound pattern
    blinkGreenCountdown(3, 1);

    // Activate Yellow LED
    digitalWrite(12, HIGH);
    countdown(2);

    // Deactivate Yellow LED
    digitalWrite(12, LOW);
}
