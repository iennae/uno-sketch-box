# Random Winner Picker

This sketch simulates a "random winner" picker with a visual spinning effect, where one of four LEDs is randomly selected and stays lit. It incorporates a technique to improve the randomness of the `random()` function by seeding it with analog noise.

## Parts List

*   Arduino Uno
*   4 x LEDs (e.g., Red, Green, Green, Blue)
*   4 x 220 Ohm Resistors (or similar, depending on your LEDs)
*   Jumper Wires
*   Breadboard (optional, for easier wiring)

## Wiring

Connect the long leg (anode) of each LED to a digital pin through a 220 Ohm resistor. Connect the short leg (cathode) of each LED to GND.

It's recommended to leave Analog Pin A0 unconnected (floating) to maximize the "static noise" it picks up for `randomSeed()`.

| Component   | Pin       |
| ----------- | --------- |
| Red LED     | Pin 8     |
| Green LED 1 | Pin 10    |
| Green LED 2 | Pin 11    |
| Blue LED    | Pin 12    |

**Pin Configuration:**

The pin assignments for the LEDs are defined at the top of the `.ino` file in the `pins` array. These values reflect the wiring used in this example.

For a detailed explanation on how to modify the pin configuration to match your own setup, please see the [main LEDs README](../README.md).

## Code Explanation

The `setup()` function performs the main logic of the sketch:
1.  **Random Seed**: `randomSeed(analogRead(0))` reads the electrical noise from the unconnected Analog Pin A0. This provides a more truly random starting point for the `random()` function, preventing the same sequence of "random" numbers from occurring each time the Arduino powers on.
2.  **Pin Initialization**: The specified digital pins are initialized as outputs.
3.  **Visual Spin Effect**: A `for` loop creates a visual "spinning" effect, lighting up each LED sequentially. The `delay(40 + (i * 7))` causes the spin to gradually slow down, adding to the visual appeal before the winner is picked.
4.  **Pick Winner**: `random(0, 4)` generates a random number between 0 and 3 (inclusive), which is used as an index to select a `winner` LED from the `pins` array.
5.  **Light Winner**: The selected `winner` LED is then turned HIGH and stays lit.

The `loop()` function is empty, as the sketch's primary action (picking and displaying the winner) is completed once in the `setup()` function. The winning LED remains lit until the Arduino is reset or powered off.

## Troubleshooting

*   **Always landing on the same LED**: If the sketch always picks the same LED (e.g., blue), it's likely due to the `random()` function producing a predictable sequence. Ensure you have `randomSeed(analogRead(0))` in your `setup()` function, and that Analog Pin A0 is left unconnected (floating) to gather sufficient electrical noise for a good seed.
