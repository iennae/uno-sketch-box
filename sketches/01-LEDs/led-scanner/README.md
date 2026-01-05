# LED Scanner

A sketch that creates a classic "scanner" effect, reminiscent of the Cylon eye from Battlestar Galactica.

## Parts List

*   Arduino Uno
*   4 x LEDs (e.g., 1 Red, 1 Blue, 2 Green)
*   4 x 1KΩ Resistors (brown-black-red-gold), one for each LED. Values from 300Ω to 2KΩ are also suitable.
*   Jumper Wires
*   Breadboard 

## Wiring

Connect the long leg (anode) of each LED to a digital pin through a 1KΩ resistor. Connect the short leg (cathode) of each LED to GND.

| Component   | Pin       |
| ----------- | --------- |
| Red LED     | Pin 8     |
| Blue LED    | Pin 12    |
| Green LED 1 | Pin 11    |
| Green LED 2 | Pin 10    |

**Pin Configuration:**

The pin assignments for the LEDs are defined at the top of the `.ino` file in the `pins` array. These values reflect the wiring used in this example.

For a detailed explanation on how to modify the pin configuration to match your own setup, please see the [main LEDs README](../README.md).

## Code Explanation

The `setup()` function initializes the specified digital pins as outputs.

The `loop()` function controls the scanning effect. It uses two `for` loops:
1.  The first loop lights up each LED from the first to the last, one at a time, with a delay.
2.  The second loop then lights up the LEDs in reverse order (bouncing back) from the second-to-last to the second LED.

The `delay(300)` makes the movement visible.

## Troubleshooting

*   If all lights are blinking at the same rate and not sequentially, check your wiring. Ensure each LED is connected to its own dedicated digital pin and not all accidentally wired to the same pin (e.g., Pin 13).
*   If an LED isn't lighting up, double-check its polarity (long leg to positive/resistor/pin, short leg to GND) and ensure it's properly connected to the assigned pin.
