# Police Strobe

This sketch simulates a police strobe light effect, rapidly flashing red and blue LEDs alternately.

## Parts List

*   Arduino Uno
*   1 x Red LED
*   1 x Blue LED
*   2 x 1KΩ Resistors (brown-black-red-gold), one for each LED. Values from 300Ω to 2KΩ are also suitable.
*   Jumper Wires
*   Breadboard 

## Wiring

Connect the long leg (anode) of the Red LED to digital Pin 8 through a 1KΩ resistor. Connect the short leg (cathode) of the Red LED to GND.
Connect the long leg (anode) of the Blue LED to digital Pin 12 through a 1KΩ resistor. Connect the short leg (cathode) of the Blue LED to GND.

The other pins (10 and 11) are declared as OUTPUTs in the code, but not used in the `loop()` function for the strobe effect. You can choose to use them for additional LEDs or ignore them if only using red and blue.

| Component | Pin       |
| --------- | --------- |
| Red LED   | Pin 8     |
| Blue LED  | Pin 12    |

**Pin Configuration:**

The pin assignments for the LEDs are explicitly defined in the `setup()` and `loop()` functions. These values reflect the wiring used in this example.

For a detailed explanation on how to modify the pin configuration to match your own setup, please see the [main LEDs README](../README.md).

## Code Explanation

The `setup()` function initializes digital pins 8 and 12 as outputs. Pins 10 and 11 are also set as outputs, but they are not utilized in the `loop()` for this specific strobe effect.

The `loop()` function continuously alternates between flashing the red and blue LEDs:
1.  **Red Flash**: A `for` loop makes the red LED (Pin 8) flash rapidly three times. Each flash involves turning the LED HIGH, waiting 40 milliseconds, turning it LOW, and waiting another 40 milliseconds.
2.  **Blue Flash**: Immediately after the red flashes, another `for` loop does the same for the blue LED (Pin 12), flashing it rapidly three times.

This creates a quick, alternating red-blue strobe pattern.
