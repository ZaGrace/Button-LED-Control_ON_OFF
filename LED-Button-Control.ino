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
