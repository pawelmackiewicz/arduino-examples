#include <IRremote.h>

#define red_LED 13
#define green_LED_1 11
#define green_LED_2 12
#define yellow_LED 10


int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(red_LED, OUTPUT);
  pinMode(yellow_LED, OUTPUT);
  pinMode(green_LED_1, OUTPUT);
  pinMode(green_LED_2, OUTPUT);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
     if (irrecv.decode(&results)) {
 
      switch (results.value) {
         case 4045713590:
            Serial.println("prev");
            digitalWrite(green_LED_1, HIGH);
            delay(500);
            digitalWrite(green_LED_1, LOW);
            break;
 
         case 16712445:
            Serial.println("next");
            digitalWrite(green_LED_2, HIGH);
            delay(500);
            digitalWrite(green_LED_2, LOW);
            break;
 
         case 16761405:
            Serial.println("play");
            digitalWrite(red_LED, HIGH);
            delay(500);
            digitalWrite(red_LED, LOW);
            break;
 
         case 16748655:
            Serial.println("eq");
            digitalWrite(yellow_LED, HIGH);
            delay(500);
            digitalWrite(yellow_LED, LOW);
            break;
         }
         Serial.println(results.value);
         Serial.print(results.rawlen);
         Serial.println(" intervals.");
         Serial.println(int(results.rawbuf));
 
   irrecv.resume();
   }
}
