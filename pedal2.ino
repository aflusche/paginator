// pedal
//
// changelog:
// v1 - basic operation, LED flashes on when pedal pressed
// v2 - LED on when Teensy on, LED flashes OFF when pedal pressed
//    - auto power off after X mins of inactivity
//    - long press to return to beginning of doc & go home
//    - better power management

// Library for debouncing - https://github.com/thomasfredericks/Bounce-Arduino-Wiring
#include <Bounce2.h>

// Library to turn Teensy off - https://github.com/FrankBoesing/T4_PowerButton/
#include <T4_PowerButton.h>

// connect foot pedal switch to this pin and GND
#define SWITCH_PIN 2
// keys
#define NEXT_KEY KEY_RIGHT_ARROW
#define PREV_KEY KEY_LEFT_ARROW
#define HOME_KEY KEY_HOME
// button press lengths
#define LEN_SHORT 750
#define LEN_MID 1500
#define LEN_LONG 2500
// how long to wait (in milliseconds) before auto off
#define AUTO_OFF_TIME 7200000 // 120 minutes

Bounce* bouncer;
unsigned long last_keypress = millis();
unsigned long now = 0;
bool press_key = false;

void startup_late_hook(){
  // init all pins as OUTPUT for better power management, per https://www.pjrc.com/teensy/low_power.html
  for (uint8_t i = 0; i < CORE_NUM_DIGITAL; i++) {
      pinMode(i, OUTPUT); 
      digitalWrite(i, HIGH);
  }
}

void setup() {
  // Use built in LED for status
  pinMode(LED_BUILTIN, OUTPUT);
  // LED should show ON
  digitalWrite(LED_BUILTIN, HIGH);

  // Setup the button with an internal pull-up
  pinMode(SWITCH_PIN,INPUT_PULLUP);
  bouncer = new Bounce();
  // After setting up the button, setup the Bounce instance
  bouncer->attach(SWITCH_PIN);
  bouncer->interval(50);
}

void loop() {
  // Update the Bounce instance
  bouncer->update();

  // current time
  now = millis();

  // if button just went DOWN, start counter
  if (bouncer->changed() && bouncer->rose()) {
    last_keypress = millis();
  }

  // if button just went UP, see how long it was down for
  if (bouncer->changed() && bouncer->fell()) {

    // short press
    if (now - last_keypress < LEN_SHORT) {
      Keyboard.press(NEXT_KEY);
      delay(10);
      Keyboard.releaseAll();

      // flash LED off once
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
    
    // mid press
    } else if (now - last_keypress >= LEN_SHORT && now - last_keypress < LEN_LONG) {
      Keyboard.press(PREV_KEY);
      delay(10);
      Keyboard.releaseAll();

      // flash LED off twice
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);

    // long press
    } else if (now - last_keypress > LEN_LONG) {
      Keyboard.press(PREV_KEY);
      delay(10);
      Keyboard.releaseAll();
      Keyboard.press(PREV_KEY);
      delay(10);
      Keyboard.releaseAll();
      Keyboard.press(PREV_KEY);
      delay(10);
      Keyboard.releaseAll();
      Keyboard.press(HOME_KEY);
      delay(10);
      Keyboard.releaseAll();

      // flash LED off three times
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

  // if we've had ZERO activity in X time, shut down Teensy
  if (now - last_keypress > AUTO_OFF_TIME)
    arm_power_down();
}