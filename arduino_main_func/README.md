This lesson is heavily inspired by a [youtube video from Wokwi](https://www.youtube.com/watch?v=-XPrSScamXc), I really enjoyed the teaching progressing throughout the video and how he inject bitesize knowledge as he modify the code step by step.

### Optimization 1 - override main()
Instead of setup() and loop() function we can directly override the main() by creating our own main function. We see that in the core avr code, the main function calls setup() and loop(), with some additional invokation. 

ref: https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/main.cpp?plain=1#L43-L48

### Optimization 2 - remove the standard library
`pinMode()` and `digitalWrite()` are from the arduino.c standard libaray instead of invoking a function call from the libaray we can we can modify the pins directly. (ref: https://docs.arduino.cc/retired/hacking/software/PortManipulation/). Also notice that since we didn't use the default main(), we did not initialize any variables from the standard libaray, like the timer, so the `delay()` function will also not work. We will replace it with two for loops.

Note that we are no longer using any of the standard library functions, the compiler (linker) will not add the library into our complied code so the program size should decrease dramatically

However, if you physically setup the LED, you should see the LED gets dimmer, not blinking. If you have an o-scope and measure the output signal you would find that the LED is flashing extremely rapidly - **it is avoiding the for loop all together! NOT GOOD!!**, we violated program correctness during our optimization

### Optimization 3 - reestablish correctness
The reason for the problem encoundered in `blinky2.ino` is because the C++ compiler is smart enough to optimize away the two for loops, since they are not doing anything in the program. So we can use the `asm("")` command to directly tell the compiler (the assembler to be exact) to not optimize this loop. 

This will increase the size of the code compared to blinky2, but it is the correct logic. And with that we optimized our blinky program successfully!

### Conclusion
Through this process we learned 
- main() override in Arduino - avoid initiate unnecessary code
- Direct pin manipulation - avoid calling standard library functions (which might be bloated for our purpose) 
- Compiler can link libraries with our code - can be space inefficient for large libaraies + long time to compile
- Compiler can optimize code blocks away - which can affect code correctness (wrong behaviour)

Remark 1: Standard libaraies are ment to be universal, they are optimized for ease of use in most development scenarios. The tradeoff for this universality is their efficiencies. So, avoiding the standard libaray by accessing the pins directly and using vanilla C code (native contstracts like for loops and main func), we are able to make our code more space efficient for this specific application.

Remark 2: Optimization requires intimate knowledge of the **tools you are working with** and **the resulting behaviour your want**. We were able to identify the issue in `blinky2.ino` because we saw the electrical behaviour of the LED was not correct. Then we were able to diagnose and fix the issue thanks to our knowledge of the C++ compiler. 
