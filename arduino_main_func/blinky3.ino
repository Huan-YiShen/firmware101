//// Optimization 3 - reestablish correctness
// adding asm() to avoid assembler optimization

int main() {
    DDRB = 0xff;

    while() {
        PORTB = 0xff;
        for (long i = 0; i < 50000; i++) {
            asm("");
        } 
        PORTB = 0x00;
        for (long i = 0; i < 50000; i++) { 
            asm("");
        } 
    }

    return 0;
}