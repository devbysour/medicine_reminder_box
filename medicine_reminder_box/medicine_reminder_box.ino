#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"
#include "secrets.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
RTC_DS3231 rtc;

// Pins
#define BTN_UP 14
#define BTN_DOWN 27
#define BTN_SELECT 26
#define BUZZER 25

// Reminder variables
int remindHour[3] = {8, 13, 20};
int remindMinute[3] = {0, 0, 0};

int currentMenu = 0;
int currentReminder = 0;
bool editing = false;

void setup() {
  Serial.begin(115200);

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  if (!rtc.begin()) {
    while (true);
  }
}

void loop() {
  DateTime now = rtc.now();

  checkAlarm(now);

  display.clearDisplay();
  display.setCursor(0, 0);

  display.println("Medicine Reminder Box");
  display.println("---------------------");

  display.print("Current Time: ");
  display.print(now.hour());
  display.print(":");
  display.println(now.minute());

  display.println("");

  display.print("Reminder ");
  display.print(currentReminder + 1);
  display.print(": ");
  display.print(remindHour[currentReminder]);
  display.print(":");
  display.println(remindMinute[currentReminder]);

  display.println("");
  display.println("UP/DOWN to edit");
  display.println("SELECT next");

  handleButtons();

  display.display();
  delay(200);
}

void handleButtons() {
  if (!digitalRead(BTN_SELECT)) {
    currentReminder = (currentReminder + 1) % 3;
    delay(250);
  }

  if (!digitalRead(BTN_UP)) {
    remindMinute[currentReminder] = (remindMinute[currentReminder] + 1) % 60;
    delay(200);
  }

  if (!digitalRead(BTN_DOWN)) {
    remindMinute[currentReminder] = (remindMinute[currentReminder] - 1 + 60) % 60;
    delay(200);
  }
}

void checkAlarm(DateTime now) {
  for (int i = 0; i < 3; i++) {
    if (now.hour() == remindHour[i] && now.minute() == remindMinute[i]) {
      tone(BUZZER, 1000);
      display.clearDisplay();
      display.setCursor(0, 20);
      display.setTextSize(2);
      display.println("TAKE MEDICINE!");
      display.display();
      delay(1000);
    } else {
      noTone(BUZZER);
    }
  }
}
 