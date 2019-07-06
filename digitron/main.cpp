char num;



void setup() {

  Serial.begin(9600);

  for (char i = 2; i < 6; i++)

    pinMode(i, OUTPUT);

}



void loop() {

  while (Serial.available() > 0) {

    num = Serial.read();

    if (isDigit(num)) {

      num -= '0';

      for (char i = 0; i < 4; i++)

        digitalWrite(i + 2, (num >> i) & 1u);

    }

  }

  delay(10);

}

