# Uno Sketch Box

A collection of starter Arduino sketches for the Arduino Uno, designed to help beginners explore various functionalities and concepts.

## Table of Contents

*   [Getting Started](#getting-started)
*   [Sketches](#sketches)
    *   [01-LEDs](#01-leds)
*   [Contributing](#contributing)
*   [License](#license)

## Pre-Requisite Knowledge

Arduino uses standard C-style comment syntax. These are essential for documenting hardware configurations, such as which physical pins are connected to which components.

* **Block Comments:** Wrapped in `/* ... */`. Typically used for file headers and licensing.
* **Inline Comments:** Started with `//`. Used for line-by-line logic explanation.

### The `setup()` Function: Initialization

In a standard C++ program, execution starts and ends with `main()`. In Arduino, the `main()` function is hidden by the build system, which instead calls two specific entry points. The first is `setup()`.

**`setup()`** runs exactly **once** upon power-up or hardware reset. This is where you perform "one-time" configuration.


```C++
void setup() {
  // Configures the specified pin to behave as an OUTPUT.
  // LED_BUILTIN is a macro that maps to the onboard LED pin (usually pin 13).
  pinMode(LED_BUILTIN, OUTPUT);
}
```

- **`pinMode(pin, mode)`**: This function sets the data direction register for the GPIO.
- **`LED_BUILTIN`**: An environment-defined constant. Using this instead of a hardcoded integer (like `13`) ensures portability across different Arduino boards.
    
### The `loop()` Function: The Super-Loop

After `setup()` finishes, the microcontroller enters the **`loop()`** function. This function executes sequentially and, upon reaching the closing brace, immediately restarts from the top. This is a standard "super-loop" architecture used in embedded programming.

```C++
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Set the pin voltage to 5V (or 3.3V)
  delay(1000);                      // Block execution for 1000 milliseconds
  digitalWrite(LED_BUILTIN, LOW);   // Set the pin voltage to 0V (Ground)
  delay(1000);                      // Block execution for 1000 milliseconds
}
```

#### Key Technical Operations:

- **`digitalWrite(pin, value)`**: This sets the state of the pin. `HIGH` applies voltage (logic 1), and `LOW` connects the pin to ground (logic 0).
- **`delay(ms)`**: This is a **blocking** function. The processor "spins" in a tight loop for the specified number of milliseconds, preventing any other code from executing during this window.

### Syntax and Structure 

- **Statement Termination**: Every statement must end with a semicolon (`;`). Forgetting this is the most common cause of compiler errors in C-based languages
- **Case Sensitivity**: Like most modern languages, `pinMode` is distinct from `pinmode`.
- **Function Invocation**: This is a standard function call. You are passing two arguments to the `pinMode` function to change the state of the microcontroller's hardware

## Getting Started

To use these sketches, you'll need:

*   An Arduino Uno board
*   The Arduino IDE installed on your computer (available at [arduino.cc](https://www.arduino.cc/))
*   A USB A-to-B Data/Sync cable to connect your Arduino to your computer (the USB-B connector is the blocky, square-ish end that plugs into the Arduino Uno)
*   Basic electronic components as specified in each sketch's `README.md`

### How to Use a Sketch

1.  Navigate to the desired sketch's folder (e.g., `sketches/01-leds/led-scanner`).
2.  Open the `.ino` file (e.g., `led-scanner.ino`) in the Arduino IDE.
3.  Connect your Arduino Uno board to your computer via USB.
4.  In the Arduino IDE, select your board (`Tools > Board > Arduino AVR Boards > Arduino Uno`) and the correct port (`Tools > Port`).
5.  Upload the sketch to your Arduino board by clicking the "Upload" button (right arrow icon) in the IDE.
6.  Refer to the `README.md` within each sketch's folder for specific wiring instructions, parts lists, and code explanations.

### Learning Resources

If you're new to Arduino, a great place to start is the [Adafruit Arduino Lesson Series](https://www.ladyada.net/learn/arduino/index.html), which provides a comprehensive introduction to Arduino basics.

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