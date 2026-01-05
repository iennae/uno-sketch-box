# Uno Sketch Box

A collection of starter Arduino sketches for incrementally learning hardware fundamentals towards my ultimate goal: building a functional LEGO droid.


## ⚠️ Disclaimer & Liability
Use at your own risk. This project is a personal learning journey documented for educational purposes.

No Warranty: This code is provided "as is" without warranty of any kind, express or implied.

No Support: As this is a personal hobby project, I cannot provide active support or guarantee compatibility with your specific hardware configuration.

Hardware Variation: Arduino kits—especially vintage or third-party kits—can vary significantly in pinouts and power requirements. Always verify your wiring and power levels before uploading code to avoid damaging your components.

## Table of Contents

* [📓 The Journey](#-the-journey) 
* [Hardware Fundamentals](#hardware-fundamentals)
* [Core Software Concepts](#core-software-concepts)
* [Getting Started](#getting-started)
* [Sketches](#sketches)
* [Contributing](#contributing)
* [License](#license)


## 📓 The Journey

![DEV.to](https://img.shields.io/badge/Project_Blog-DEV.to-0a0a0a?style=for-the-badge&logo=devdotto&logoColor=white)

This project is being documented as a series of articles on DEV.to, covering everything from unboxing 16-year-old hardware to (hopefully) an eventual LEGO droid.

* **Part 1: [From 2010 Dust to Droid Dreams](https://dev.to/sigje/from-2010-dust-to-droid-dreams-relearning-the-arduino-4f5g)** Relearning the Arduino UNO

## Hardware Fundamentals

Before wiring your components, keep these two concepts in mind:

### 1. The Breadboard
Your breadboard may vary from what I used (a Full-size breadboard). You may have a  **Mini Breadboard** (no side rails) or a **Full-Size/Half-Size Breadboard** (with rails). 

* **Terminal Strips (A-E and F-J):** These are the main connection points.
    * Pins in a single numbered row (like 10A, 10B, 10C, 10D, 10E) are **electrically connected**.
    * **The Trench:** The center notch separates columns A-E from F-J. This is vital for plugging in Integrated Circuits (ICs) so their legs don't short-circuit.
* **Power Rails (Plus/Minus):** Found on larger boards. These run the entire length of the board.
    * **Best Practice:** Connect the Arduino's `5V` pin to the red (+) rail and `GND` to the blue (-) rail. This gives you a "power bus" accessible from anywhere on the board.
    * *If using a Mini Breadboard:* You will need to manually route your Ground wires back to the Arduino's GND pins.

### 2. LED Polarity & Protection
LEDs are diodes, meaning they only allow current to flow in one direction.
* **The Long Leg (Anode):** Connects to the positive voltage (Digital Pin).
* **The Short Leg (Cathode):** Connects to Ground (GND).
* **Resistors:** Always place a **220Ω resistor** in series with your LED to limit current and prevent damage to the LED or the Arduino.

---

## Core Software Concepts

Arduino uses standard C-style syntax. Documentation is handled via comments:
* **Block Comments:** Wrapped in `/* ... */`. Typically used for headers.
* **Inline Comments:** Started with `//`. Used for line-by-line logic.

### The Arduino Lifecycle
Unlike a standard computer program that runs once and stops, an Arduino sketch follows a continuous loop pattern.

##1.  **`setup()`**: Runs exactly **once** upon power-up or reset. Use this to configure pin modes.
2.  **`loop()`**: Runs sequentially from top to bottom, then **immediately restarts** at the top. This is the "Super-Loop" architecture used in embedded systems.

```C++
void setup() {
  // LED_BUILTIN is a macro for Pin 13
  pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn LED on (5V)
  delay(1000);                     // Wait 1 second (Blocking)
  digitalWrite(LED_BUILTIN, LOW);  // Turn LED off (0V)
  delay(1000);                     // Wait 1 second
}

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
*   The Arduino IDE installed on your computer (available at [arduino.cc](https://www.arduino.cc/)). You could also use the Arduino CLI. 
*   A USB A-to-B Data/Sync cable to connect your Arduino to your computer (the USB-B connector is the blocky, square-ish end that plugs into the Arduino Uno)
*   Basic electronic components or their equivalents as specified in each sketch's `README.md`

### How to Use a Sketch

1.  Navigate to the desired sketch's folder (e.g., `sketches/01-LEDs/led-scanner`).
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

*   **[LED Scanner](sketches/01-LEDs/led-scanner/README.md)**: Creates a classic scanning light effect.
*   **[Binary Counter](sketches/01-LEDs/binary-counter/README.md)**: Displays numbers 0-15 in binary using four LEDs.
{% youtube 1vEevR4qY-8 %} 
*   **[Police Strobe](sketches/01-LEDs/police-strobe/README.md)**: Simulates a police car strobe light with alternating red and blue flashes.
{% youtube mL4Sdts8zg4 %} 
*   **[Random Winner Picker](sketches/01-LEDs/random-winner-picker/README.md)**: A spinning light that randomly selects and illuminates one LED.
{% youtube YaFgHoTzhx0 %} 

## Contributing

Contributions welcome. If you have a new sketch, an improvement to an existing one, or a bug fix:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourFeatureName` or `git checkout -b bugfix/BugFixName`).
3.  Make your changes, adhering to the existing coding style and documentation conventions.
4.  Ensure your `README.md` for new sketches includes a parts list, wiring instructions, and code explanation, similar to the existing examples.
5.  Commit your changes (`git commit -m 'Add new feature'`).
6.  Push to the branch (`git push origin feature/YourFeatureName`).
7.  Open a Pull Request.

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE](LICENSE) file for details.