//// Optimization 2 - remove the standard library
// replace digitalWrite() with DDRB control
// replace pinMode() with PORTB control
// ref: https://docs.arduino.cc/retired/hacking/software/PortManipulation/

int main() {
    DDRB = 0xff; // setting pin 8-13 (digital pins) to output

    while() {
        PORTB = 0xff;
        for (long i = 0; i < 50000; i++) { /*do nothing - replace delay()*/ } 
        PORTB = 0x00;
        for (long i = 0; i < 50000; i++) { /*do nothing - replace delay()*/ } 
    }

    return 0;
}