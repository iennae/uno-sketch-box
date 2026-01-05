# Uno Sketch Box

A collection of starter Arduino sketches for the Arduino Uno, designed to help beginners explore various functionalities and concepts.

## Table of Contents

*   [Getting Started](#getting-started)
*   [Sketches](#sketches)
    *   [01-LEDs](#01-leds)
*   [Contributing](#contributing)
*   [License](#license)

## Getting Started

To use these sketches, you'll need:

*   An Arduino Uno board
*   The Arduino IDE installed on your computer (available at [arduino.cc](https://www.arduino.cc/))
*   A USB cable to connect your Arduino to your computer
*   Basic electronic components as specified in each sketch's `README.md`

### How to Use a Sketch

1.  Navigate to the desired sketch's folder (e.g., `sketches/01-leds/led-scanner`).
2.  Open the `.ino` file (e.g., `led-scanner.ino`) in the Arduino IDE.
3.  Connect your Arduino Uno board to your computer via USB.
4.  In the Arduino IDE, select your board (`Tools > Board > Arduino AVR Boards > Arduino Uno`) and the correct port (`Tools > Port`).
5.  Upload the sketch to your Arduino board by clicking the "Upload" button (right arrow icon) in the IDE.
6.  Refer to the `README.md` within each sketch's folder for specific wiring instructions, parts lists, and code explanations.

## Sketches

### 01-LEDs

A collection of sketches demonstrating various ways to control Light Emitting Diodes (LEDs), covering basic output, patterns, and random effects.

*   **[LED Scanner](sketches/01-leds/led-scanner/README.md)**: Creates a classic scanning light effect.
*   **[Binary Counter](sketches/01-leds/binary-counter/README.md)**: Displays numbers 0-15 in binary using four LEDs.
*   **[Police Strobe](sketches/01-leds/police-strobe/README.md)**: Simulates a police car strobe light with alternating red and blue flashes.
*   **[Random Winner Picker](sketches/01-leds/random-winner-picker/README.md)**: A spinning light that randomly selects and illuminates one LED.

## Contributing

We welcome contributions! If you have a new sketch, an improvement to an existing one, or a bug fix:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourFeatureName` or `git checkout -b bugfix/BugFixName`).
3.  Make your changes, adhering to the existing coding style and documentation conventions.
4.  Ensure your `README.md` for new sketches includes a parts list, wiring instructions, and code explanation, similar to the existing examples.
5.  Commit your changes (`git commit -m 'Add new feature'`).
6.  Push to the branch (`git push origin feature/YourFeatureName`).
7.  Open a Pull Request.

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE](LICENSE) file for details.