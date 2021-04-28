//default board is 7th down

// uncomment XInput for emulating xbox controller
// Problem with XInput on rocket league at least is that it starts split screen lol, therefore we will use keyboard.
//#include <XInput.h>
#include <Keyboard.h>

// pins on the arduino
const int LEFT_SWITCH_PIN = 3;
const int RIGHT_SWITCH_PIN = 2;

// button state
int left_button_flag = 0;
int right_button_flag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RIGHT_SWITCH_PIN, INPUT_PULLUP);
  pinMode(LEFT_SWITCH_PIN, INPUT_PULLUP);
  //Serial.begin(9600);
  //XInput.begin();
  Keyboard.begin();
}

void loop() {
  bool leftClickPressed = digitalRead(LEFT_SWITCH_PIN) == LOW;
  bool rightClickPressed = digitalRead(RIGHT_SWITCH_PIN) == LOW;

  if (leftClickPressed && !left_button_flag) {
    left_button_flag = 1;
    //Serial.println("Left Click Pressed");
    //XInput.press(BUTTON_Y);
    Keyboard.press(' ');
  } else if (!leftClickPressed && left_button_flag) {
    left_button_flag = 0;
    //Serial.println("Left Click released");
    //XInput.release(BUTTON_Y);
    Keyboard.release(' ');
  }
 
  if (rightClickPressed && !right_button_flag) {
    right_button_flag = 1;
    //Serial.println("Right Click Pressed");
    //XInput.press(BUTTON_X);
    Keyboard.press(KEY_TAB);
  } else if (!rightClickPressed && right_button_flag) {
    right_button_flag = 0;
    //Serial.println("Right Click released");
    //XInput.release(BUTTON_X);
    Keyboard.release(KEY_TAB);
  }

  delay(1);
}
