# Smart Baby Monitor (Arduino Uno)

A simulation-ready baby monitoring system built on Arduino Uno using Tinkercad. Features include:

- **Cry detection** using a potentiometer simulating sound
- **Temperature monitoring** via TMP36 sensor
- **Gas level detection** using gas sensor analog output
- **Room brightness detection** with a photoresistor for automatic night light control
- **Motion detection** through a PIR sensor
- **Auto-swing cradle** using a servo on cry detection
- **Real-time display** on a 16×2 I2C LCD in Tinkercad
- **LCD backlight alerts** and **Serial Monitor debugging**

## 🚀 How It Works

1. Analog sensors (mic, temp, gas, light) feed readings to Arduino.
2. PIR detects baby movement.
3. Servo swings cradle when cry is detected.
4. Night light LED turns on in the dark.
5. Information displayed on LCD and logged via Serial Monitor.
6. Backlight blinks on alerts (cry, gas, movement).

## 🧪 Setup Instructions

- Connect sensors and components as per the pin definitions in code.
- Use Tinkercad’s I2C LCD option and link SDA → A4, SCL → A5, VCC → 5V, GND → GND.
- Run in Tinkercad or with actual hardware using `Adafruit_LiquidCrystal` (Tinkercad’s I2C sim).

Feel free to expand with Wi‑Fi, real cry microphones, emotion detection, or real-time alerts!

---

