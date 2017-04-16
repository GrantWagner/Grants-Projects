/*
 * 
 * IO layout:
 *  * strobe rows, pins 0 - 4
 *  * capslock led pin 5
 *  * function led pin 6
 *  * function key pin 7
 *  * sample columns, pins 8-15
 * 
 * ┌──┬─────┬───┬───┬─────┬──────┬─────┬─────┬────┐
 * │  │8    │9  │10 │11   │12    │13   │14   │15  │
 * ├──┼─────┼───┼───┼─────┼──────┼─────┼─────┼────┤
 * │0 │6    │7  │8  │9    │0     │MINUS│EQUAL│BKSP│
 * ├──┼─────┼───┼───┼─────┼──────┼─────┼─────┼────┤
 * │1 │Y    │U  │I  │O    │P     │[    │ ]   │BKSL│
 * ├──┼─────┼───┼───┼─────┼──────┼─────┼─────┼────┤
 * │2 │H    │J  │K  │L    │SMCLN │QUOTE│ENTER│    │
 * ├──┼─────┼───┼───┼─────┼──────┼─────┼─────┼────┤
 * │3 │B    │N  │M  │COMMA│PERIOD│SLASH│SHIFT│    │
 * ├──┼─────┼───┼───┼─────┼──────┼─────┼─────┼────┤
 * │4 │SPACE│GUI│ALT│CTRL │FN    │     │     │    │ 
 * └──┴─────┴───┴───┴─────┴──────┴─────┴─────┴────┘
 */
#include <Bounce.h>

//#define TESTING

//KEYBOARD STATE SUPPORT
const int STATE_MAX = 2;

//KEYBOARD ROW SCAN
const int ROW_MAX = 5;
const int COLUMN_MAX = 8;
const int PACKET_MAX = 6;

//IO DEFINIONS
const int ROW_OFFSET = 0;
const int COLUMN_OFFSET = 8;
const int CAPSLOCK_LED_PIN = 5;
const int FUNCTION_LED_PIN = 6;
const int FUNCTION_KEY_PIN = 7;

//Global State Vars
int stateCurrent = 0;
Bounce fnKey = Bounce( FUNCTION_KEY_PIN,10 ); 

//key constants are from /arduino-1.8.1/hardware/teensy/avr/cores/teensy/keylayouts.h
const int KEY_NONE = 0;
int keysMapVal[STATE_MAX][ROW_MAX][COLUMN_MAX] = {{
  { KEY_6,     KEY_7,    KEY_8,         KEY_9,     KEY_0,         KEY_MINUS,      KEY_EQUAL,       KEY_BACKSPACE },
  { KEY_Y,     KEY_U,    KEY_I,         KEY_O,     KEY_P,         KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_BACKSLASH },
  { KEY_H,     KEY_J,    KEY_K,         KEY_L,     KEY_SEMICOLON, KEY_QUOTE,      KEY_ENTER,       KEY_NONE },
  { KEY_B,     KEY_N,    KEY_M,         KEY_COMMA, KEY_PERIOD,    KEY_SLASH,      KEY_NONE,        KEY_NONE },
  { KEY_SPACE, KEY_NONE, KEY_NONE,      KEY_NONE,  KEY_NONE,      KEY_NONE,       KEY_NONE,        KEY_NONE }
}, {
  { KEY_F6,    KEY_F7,   KEY_F8,        KEY_F9,    KEY_F10,       KEY_F11,        KEY_F12,         KEY_DELETE },
  { KEY_NONE,  KEY_NONE, KEY_PAGE_UP,   KEY_NONE,  KEY_NONE,      KEY_NONE,       KEY_NONE,        KEY_NONE },
  { KEY_NONE,  KEY_HOME, KEY_PAGE_DOWN, KEY_END,   KEY_NONE,      KEY_NONE,       KEY_NONE,        KEY_NONE },
  { KEY_NONE,  KEY_NONE, KEY_NONE,      KEY_NONE,  KEY_NONE,      KEY_NONE,       KEY_NONE,        KEY_NONE },
  { KEY_NONE,  KEY_NONE, KEY_NONE,      KEY_NONE,  KEY_NONE,      KEY_NONE,       KEY_NONE,        KEY_NONE }
}};
int keysMapMod[ROW_MAX][COLUMN_MAX] = {
  { KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE },
  { KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE },
  { KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE },
  { KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, MODIFIERKEY_RIGHT_SHIFT
                                                                        , KEY_NONE },
  { KEY_NONE, MODIFIERKEY_RIGHT_GUI, 
                        MODIFIERKEY_RIGHT_ALT, 
                                  MODIFIERKEY_RIGHT_CTRL, 
                                            KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE }
};

void setup() {
  #ifdef TESTING
    Serial.begin(9600);
  #endif
  
  for( int row = 0; row < ROW_MAX; row++) {
    pinMode(row + ROW_OFFSET, OUTPUT);
    digitalWrite(row + ROW_OFFSET, LOW); 
  }

  pinMode(CAPSLOCK_LED_PIN, OUTPUT);      
  digitalWrite(CAPSLOCK_LED_PIN, LOW); 

  pinMode(FUNCTION_LED_PIN, OUTPUT);      
  digitalWrite(FUNCTION_LED_PIN, LOW); 

  pinMode(FUNCTION_KEY_PIN, INPUT);

  for ( int col = 0; col < COLUMN_MAX; col++) {
    pinMode(col + COLUMN_OFFSET, INPUT);
  }
}

void loop() {
  int keys[PACKET_MAX] = {0};
  int keyMod = 0;

  updateFunctionSet();
  updateCapsLockLED();
  scanKeys(keys, keyMod );
  sendPacket(keys, keyMod);
}

void updateFunctionSet() {
  fnKey.update();
  if ( fnKey.risingEdge()) {

    if (stateCurrent < STATE_MAX) {
      stateCurrent ++;
      digitalWrite(FUNCTION_LED_PIN, HIGH);
    } else {
      stateCurrent = 0;
      digitalWrite(FUNCTION_LED_PIN, LOW);
    }

    #ifdef TESTING
      Serial.print("Updated keyboard state: ");
      Serial.print(stateCurrent);
      Serial.println(".");
    #endif
  }
}
 
void updateCapsLockLED() {
  #ifdef TESTING
    Serial.print("Keyboard Led register: ");
    Serial.print(keyboard_leds;
    Serial.println(".");
  #endif

  if ( ( keyboard_leds & 2) == 0 ) {
    #ifdef TESTING
      Serial.println("Setting Capslock to off.");
    #endif
    digitalWrite(CAPSLOCK_LED_PIN, LOW);
  } else {
    #ifdef TESTING
      Serial.println("Setting Capslock to on.");
    #endif
    digitalWrite(CAPSLOCK_LED_PIN, HIGH);
  }
}

void scanKeys(int keys[PACKET_MAX], int &keyMod ) {
  int keyIndex = 0;

  for( int row = 0; row < ROW_MAX; row++) {
    int rowPin = row + ROW_OFFSET;
    #ifdef TESTING
      Serial.print("Testing row: ");
      Serial.print(row);
      Serial.print(", with pin ");
      Serial.print(rowPin);
      Serial.println(".");
    #endif
    digitalWrite(rowPin, HIGH); 

    for ( int col = 0; col < COLUMN_MAX; col++) {
      int colPin = col + COLUMN_OFFSET;
      int colVal = digitalRead(colPin);
      #ifdef TESTING
        Serial.print("Testing col: ");
        Serial.print(col);
        Serial.print(", with pin ");
        Serial.print(colPin);
        Serial.print(", with value ");
        Serial.print(colVal);
        Serial.println(".");
      #endif

      if ( colVal != 0 ) {
        //parse a key value
        if ( keyIndex < PACKET_MAX) {
          keys[keyIndex] = keysMapVal[stateCurrent][row][col];
          if ( keys[keyIndex] != 0 ) {
            keyIndex++;
            #ifdef TESTING
              Serial.print("Setting key ");
              Serial.print(keys[keyIndex]);
              Serial.println(".");
            #endif
          }
        }

        //parse a key modifier
        keyMod |= keysMapMod[row][col];
      }
    }

    //reset the pin
    digitalWrite(rowPin, LOW); 
  }
}

void sendPacket(int keys[PACKET_MAX], int keyMod ) {
  #ifdef TESTING
    Serial.print("Sending packet: ");
    Serial.print(keys[0], HEX);
    Serial.print(", ");
    Serial.print(keys[1], HEX);
    Serial.print(", ");
    Serial.print(keys[2], HEX);
    Serial.print(", ");
    Serial.print(keys[3], HEX);
    Serial.print(", ");
    Serial.print(keys[4], HEX);
    Serial.print(", ");
    Serial.print(keys[5], HEX);
    Serial.print(", Modifier: ");
    Serial.print(keyMod, HEX);
    Serial.println(".");
    delay(100);
  #else
    Keyboard.set_key1(keys[0]);
    Keyboard.set_key2(keys[1]);
    Keyboard.set_key3(keys[2]);
    Keyboard.set_key4(keys[3]);
    Keyboard.set_key5(keys[4]);
    Keyboard.set_key6(keys[5]);
    Keyboard.set_modifier(keyMod);
    Keyboard.send_now();
  #endif
}

