//// Optimization 1 - override main()
// we can directly override the main() 
// ref: https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/main.cpp?plain=1#L43-L48

int main() {
   pinMode(2, OUTPUT);

   for (;;) {
      digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(1000); // wait for a second
      digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
      delay(1000); // wait for a second
   }

   return 0;
}