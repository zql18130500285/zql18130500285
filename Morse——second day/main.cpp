#define DEBUG



class MorseBase {

  int _pin;

  const int clk = 250;



public:

  MorseBase(int8_t pin) : _pin(pin) { pinMode(pin, OUTPUT); }

  inline void dit() {

    digitalWrite(_pin, HIGH);

    delay(clk);

    digitalWrite(_pin, LOW);

    delay(clk);

#ifdef DEBUG

    Serial.print('.');

#endif

  }

  inline void dah() {

    digitalWrite(_pin, HIGH);

    delay(clk * 3);

    digitalWrite(_pin, LOW);

    delay(clk);

#ifdef DEBUG

    Serial.print('-');

#endif

  }

  inline void eoc() {

    delay(clk << 1);

#ifdef DEBUG

    Serial.print(' ');

#endif

  }

  inline void eow() {

    delay((clk << 2) + (clk << 1));

#ifdef DEBUG

    Serial.print("/");

#endif

  }

};



MorseBase x(13);



bool isInitial = true;

char ch = 0;



void setup() { Serial.begin(9600); }



void loop() {

  if (Serial.available() > 0) {

    ch = Serial.read();

    if (isUpperCase(ch))

      ch |= 0x20u;

    if (isInitial)

      isInitial = false;

    else if (ch != ' ')

      x.eoc();

    else {

      isInitial = true;

      x.eow();

    }

    switch (ch) {

      case 'a': x.dit(); x.dah(); break;

      case 'b': x.dah(); x.dit(); x.dit(); x.dit(); break;

      case 'c': x.dah(); x.dit(); x.dah(); x.dit(); break;

      case 'd': x.dah(); x.dit(); x.dit(); break;

      case 'e': x.dit(); break;

      case 'f': x.dit(); x.dit(); x.dah(); x.dit(); break;

      case 'g': x.dah(); x.dah(); x.dit(); break;

      case 'h': x.dit(); x.dit(); x.dit(); x.dit(); break;

      case 'i': x.dit(); x.dit(); break;

      case 'j': x.dit(); x.dah(); x.dah(); x.dah(); break;

      case 'k': x.dah(); x.dit(); x.dah(); break;

      case 'l': x.dit(); x.dah(); x.dit(); x.dit(); break;

      case 'm': x.dah(); x.dah(); break;

      case 'n': x.dah(); x.dit(); break;

      case 'o': x.dah(); x.dah(); x.dah(); break;

      case 'p': x.dit(); x.dah(); x.dah(); x.dit(); break;

      case 'q': x.dah(); x.dah(); x.dit(); x.dah(); break;

      case 'r': x.dit(); x.dah(); x.dit(); break;

      case 's': x.dit(); x.dit(); x.dit(); x.dit(); break;

      case 't': x.dah(); break;

      case 'u': x.dit(); x.dit(); x.dah(); break;

      case 'v': x.dit(); x.dit(); x.dit(); x.dah(); break;

      case 'w': x.dit(); x.dah(); x.dah(); break;

      case 'x': x.dah(); x.dit(); x.dit(); x.dah(); break;

      case 'y': x.dah(); x.dit(); x.dah(); x.dah(); break;

      case 'z': x.dah(); x.dah(); x.dit(); x.dit(); break;

      case '0': x.dah(); x.dah(); x.dah(); x.dah(); x.dah(); break;

      case '1': x.dit(); x.dah(); x.dah(); x.dah(); x.dah(); break;

      case '2': x.dit(); x.dit(); x.dah(); x.dah(); x.dah(); break;

      case '3': x.dit(); x.dit(); x.dit(); x.dah(); x.dah(); break;

      case '4': x.dit(); x.dit(); x.dit(); x.dit(); x.dah(); break;

      case '5': x.dit(); x.dit(); x.dit(); x.dit(); x.dit(); break;

      case '6': x.dah(); x.dit(); x.dit(); x.dit(); x.dit(); break;

      case '7': x.dah(); x.dah(); x.dit(); x.dit(); x.dit(); break;

      case '8': x.dah(); x.dah(); x.dah(); x.dit(); x.dit(); break;

      case '9': x.dah(); x.dah(); x.dah(); x.dah(); x.dit(); break;

      case ',': x.dah(); x.dah(); x.dit(); x.dit(); x.dah(); x.dah(); break;

      case '.': x.dit(); x.dah(); x.dit(); x.dah(); x.dit(); x.dah(); break;

      case '?': x.dit(); x.dit(); x.dah(); x.dah(); x.dit(); x.dit(); break;

      case '!': x.dit(); x.dit(); x.dah(); x.dah(); x.dit(); break;

      case '\"': x.dit(); x.dah(); x.dit(); x.dit(); x.dah(); x.dit(); break;

      case '\'': x.dit(); x.dah(); x.dah(); x.dah(); x.dah(); x.dit(); break;

      case '-': x.dah(); x.dit(); x.dit();x.dit(); x.dit(); x.dah(); break;

    }

  }

}
