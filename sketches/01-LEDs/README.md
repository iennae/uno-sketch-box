# 01-LEDs: Getting Started with LEDs

This collection of sketches provides a hands-on introduction to controlling Light Emitting Diodes (LEDs) with an Arduino Uno. You'll learn everything from basic on-off control to creating complex visual effects like patterns and random displays.

## A Note on Pin Configuration

**Important:** The pin numbers used in each sketch (e.g., `int pins[] = {8, 10, 11, 12};`) correspond to how the components were wired for that specific example. Your setup may be different.

You can easily change the pins to match your own wiring. The pin assignments are typically located at the top of each `.ino` file. Simply modify the pin numbers in the array or variable declarations to match the digital pins you are using on your Arduino board.

For example, if you see this in the code:
```cpp
int pins[] = {8, 12, 11, 10}; 
```
But you have wired your LEDs to pins 2, 3, 4, and 5, you would change it to:
```cpp
int pins[] = {2, 3, 4, 5}; 
```

Always check the `README.md` for each sketch for specific details on which pin corresponds to which component.
