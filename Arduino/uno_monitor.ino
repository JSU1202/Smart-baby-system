#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

Adafruit_LiquidCrystal lcd(0);  // Tinkercad-compatible I2C LCD
Servo cradleServo;

// Pin definitions
#define MIC_PIN A0
#define TEMP_PIN A1
#define GAS_PIN A2
#define LIGHT_PIN A3
#define PIR_PIN 8
#define LED_PIN 9
#define SERVO_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  cradleServo.attach(SERVO_PIN);
  cradleServo.write(90);
  
  lcd.begin(16, 2);
  lcd.print("Baby Monitor Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int micVal = analogRead(MIC_PIN);
  int tempRaw = analogRead(TEMP_PIN);
  int gasVal = analogRead(GAS_PIN);
  int lightVal = analogRead(LIGHT_PIN);
  bool motion = digitalRead(PIR_PIN) == HIGH;

  float voltage = tempRaw * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100.0;

  bool cry = micVal > 500;

  if (cry) {
    cradleServo.write(120); delay(500);
    cradleServo.write(60);  delay(500);
    cradleServo.write(90);
  }

  static bool dark = false;
  if (lightVal < 300) dark = true;
  else if (lightVal > 500) dark = false;
  digitalWrite(LED_PIN, dark);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(tempC, 1);
  lcd.print((char)223);
  lcd.print("C G:");
  lcd.print(gasVal);

  lcd.setCursor(0, 1);
  lcd.print( cry ? "Cry " : "Calm");
  lcd.print(motion? " Move " : " Still");
  lcd.print(dark? " D" : " L");

  if (cry || gasVal > 600 || motion) {
    lcd.setBacklight(1); delay(250);
    lcd.setBacklight(0); delay(250);
    lcd.setBacklight(1);
  } else {
    lcd.setBacklight(1); delay(1000);
  }

  Serial.print("Temp: "); Serial.print(tempC);
  Serial.print(" | Gas: "); Serial.print(gasVal);
  Serial.print(" | Mic: "); Serial.print(micVal);
  Serial.print(" | Light: "); Serial.print(lightVal);
  Serial.print(" | Motion: "); Serial.println(motion ? "Yes" : "No");
}
