// basic blinky program with setup() and loop()
// compare the file size and dynamic memory used for different blinky codes

void setup() {  
    // the setup function runs once when you press reset  or power the board
    // initialize digital pin 13 as an output.
   pinMode(2, OUTPUT);
}

void loop() {
   digitalWrite(2, HIGH); // turn the LED on (HIGH is the voltage level)
   delay(1000); // wait for a second
   digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
   delay(1000); // wait for a second
}