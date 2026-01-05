# Binary Counter

This sketch demonstrates a 4-bit binary counter using four LEDs. The LEDs will light up in sequence to represent numbers from 0 to 15 in binary format.

## Parts List

*   Arduino Uno
*   4 x LEDs (e.g., 1 Red, 2 Green, 1 Blue)
*   4 x 1KΩ Resistors (brown-black-red-gold), one for each LED. Values from 300Ω to 2KΩ are also suitable.
*   Jumper Wires
*   Breadboard 

## Wiring

Connect the long leg (anode) of each LED to a digital pin through a 1KΩ resistor. Connect the short leg (cathode) of each LED to GND.

| Component   | Pin       | Binary Value |
| ----------- | --------- | ------------ |
| Red LED     | Pin 8     | 1s place     |
| Green LED 1 | Pin 10    | 2s place     |
| Green LED 2 | Pin 11    | 4s place     |
| Blue LED    | Pin 12    | 8s place     |

**Pin Configuration:**

The pin assignments for the LEDs are defined at the top of the `.ino` file in the `pins` array. These values reflect the wiring used in this example.

For a detailed explanation on how to modify the pin configuration to match your own setup, please see the [main LEDs README](../README.md).

## Code Explanation

The `setup()` function initializes the specified digital pins as outputs.

The `loop()` function contains two nested `for` loops:
1.  The outer loop (`for (int count = 0; count < 16; count++)`) iterates from 0 to 15, representing the numbers to be displayed in binary.
2.  The inner loop (`for (int bit = 0; bit < 4; bit++)`) iterates through each of the four LEDs. It uses bitwise operations (`>>` for right shift and `&` for bitwise AND) to check if the current `bit` of the `count` is a 1 or a 0.
    *   `count >> bit`: Shifts the `count` value right by `bit` positions.
    *   `& 0x01`: Performs a bitwise AND with 1 to get the value of the least significant bit (which will be 0 or 1).
    *   `digitalWrite(pins[bit], ...)`: Sets the corresponding LED to HIGH (on) or LOW (off) based on the bit's value.

After displaying each binary number, there's a `delay(1000)` (1 second) before the next number is shown.
