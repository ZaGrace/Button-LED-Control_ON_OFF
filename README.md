# Button-LED-Control

## Overview
This Arduino project allows you to control an LED using a button. The LED starts off and toggles between ON and OFF with each button press. When the button is pressed, the LED turns on, and it remains on until the button is pressed again. The project uses the **INPUT_PULLUP** configuration to simplify wiring by eliminating the need for an external pull-up resistor. A debounce delay ensures accurate button press detection.

## Components Used
- Arduino Uno or compatible board  
- Push button switch (4-pin)  
- LED  
- Resistor (220Ω for LED)  

## Wiring
![image](https://github.com/user-attachments/assets/3d770e1f-540a-43b9-9bf3-a27b7dc21a7a)

- **Button Pin 1**: GND  
- **Button Pin 2**: Pin 8 (Digital Input)  
- **LED Anode**: Pin 9 (Digital Output)  
- **LED Cathode**: GND through 220Ω resistor  

## How It Works
1. The button is configured with an **INPUT_PULLUP** resistor, so it reads **HIGH** when not pressed and **LOW** when pressed.  
2. Each button press toggles the LED state between **ON** and **OFF**.  
3. The debounce delay prevents multiple readings caused by button bouncing.  
4. The LED starts in the **OFF** state and toggles with each button press.

## Code
See (https://github.com/ZaGrace/Button-LED-Control_ON_OFF/blob/main/LED-Button-Control.ino) for the full code.

```cpp
const int buttonPin = 8;  // Button connected to pin 8
const int LedPin = 9;     // LED connected to pin 9

int LedState = 0;                  // Initializes LED to 0 (OFF)
int lastButtonState = HIGH;        // Initial button state is HIGH (not pressed)
int currentButtonState;            // Stores current button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
  pinMode(LedPin, OUTPUT);          // Set LED as output
  digitalWrite(LedPin, LOW);        // Set LED starting value to OFF
}

void loop() {
  // Read button state
  currentButtonState = digitalRead(buttonPin);

  // Detect button press (LOW with pull-up)
  if (currentButtonState == LOW && lastButtonState == HIGH) { 
    LedState = !LedState;               // Toggle LED state
    digitalWrite(LedPin, LedState);     // Update LED
    delay(50);                          // Debounce delay
  }

  // Update last button state
  lastButtonState = currentButtonState;
}
