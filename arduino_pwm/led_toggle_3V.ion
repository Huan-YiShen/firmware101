/////////////////////////////////////////////////////////
Toggle LED to have 3.3V with PWM. (need hardware capctor filtering)
/////////////////////////////////////////////////////////

// const int pwmPin = 9;  // Use a PWM-capable pin (D3, D5, D6, D9, D10, D11 on Uno)
// bool ledState = 1;

// void setup() {
//   pinMode(ledState, OUTPUT);
//   pinMode(LED_BUILTIN, OUTPUT);
//   Serial.begin(9600);
//   Serial.println("Send any character to toggle LED on pin 13 (or just press ENTER)");
//   analogWrite(pwmPin, 168); // Simulate ~3.3V (PWM + Filtering)
//   digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
// }

// void loop() {
//  if (Serial.available() > 0) {
//     Serial.read();         
//      // Read the incoming byte (not used)
//     ledState = !ledState;   // Toggle the ledState
//     if (ledState == HIGH) {
//       analogWrite(pwmPin, 168); // Simulate ~3.3V (PWM + Filtering)
//       digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//     } else {
//       analogWrite(pwmPin, 0);
//       digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
//     }
//     Serial.print("LED is now ");
//     Serial.println(ledState ? "ON" : "OFF");
//   }
// }

/////////////////////////////////////////////////////////
Toggle LED normally from serial cmd (for UNO, output is 5V)
/////////////////////////////////////////////////////////
// generate 5V on UNO
const int ledPin = 13;
// const int ledPin = LED_BUILTIN;
bool ledState = HIGH;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Send any character to toggle LED on pin 13 (or just press ENTER)");
  digitalWrite(ledPin, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.read();
     // Read the incoming byte (not used)
    ledState = !ledState;   // Toggle the ledState
    digitalWrite(ledPin, ledState);
    Serial.print("LED is now ");
    Serial.println(ledState ? "ON" : "OFF");
  }
}

