#define IN1 PIN_PB2
#define IN2 PIN_PB1
#define OUT1 PIN_PC5
#define OUT2 PIN_PC4
#define OUT3 PIN_PC2
#define OUT4 PIN_PC3
#define OUT1_12V PIN_PC1
#define OUT2_12V PIN_PC0

#define OUT_ON(pin) digitalWrite(pin, LOW)
#define OUT_OFF(pin) digitalWrite(pin, HIGH)

#define OUT_12V_ON(pin) digitalWrite(pin, HIGH)
#define OUT_12V_OFF(pin) digitalWrite(pin, LOW)

#define PTT_ON(pin) !digitalRead(pin)

void setup() {
  Serial.begin(115200);
  Serial.println("PA Sequencer 2022");

  pinMode(IN1, INPUT_PULLUP);
  pinMode(IN2, INPUT_PULLUP);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT1_12V, OUTPUT);
  pinMode(OUT2_12V, OUTPUT);

  OUT_OFF(OUT1);
  OUT_OFF(OUT2);
  OUT_OFF(OUT3);
  OUT_OFF(OUT4);
  OUT_12V_OFF(OUT1_12V);
  OUT_12V_OFF(OUT2_12V);
}

void loop() {
  if(PTT_ON(IN1) || PTT_ON(IN2))
  {
    OUT_12V_OFF(OUT1_12V);
    OUT_12V_OFF(OUT2_12V);
    OUT_ON(OUT1);
    OUT_ON(OUT2);
    OUT_ON(OUT3);
    OUT_ON(OUT4);
  }
  else
  {
    OUT_12V_ON(OUT1_12V);
    OUT_12V_ON(OUT2_12V);
    OUT_OFF(OUT1);
    OUT_OFF(OUT2);
    OUT_OFF(OUT3);
    OUT_OFF(OUT4);
  }

//  Serial.print(digitalRead(OUT1));
//  Serial.print(",");
//  Serial.print(digitalRead(OUT2));
//  Serial.print(",");
//  Serial.print(digitalRead(OUT3));
//  Serial.print(",");
//  Serial.print(digitalRead(OUT4));
//  Serial.print(",");
//  Serial.print(digitalRead(OUT1_12V));
//  Serial.print(",");
//  Serial.println(digitalRead(OUT2_12V));
//  delay(100);
}
