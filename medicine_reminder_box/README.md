# Medicine Reminder Box (ESP32 + OLED + RTC + Telegram)

A smart medicine reminder system built using an **ESP32 DevKit V1 (30-pin)**, **OLED display**, **DS3231 RTC**, **buzzer**, **IR sensor**, and **Telegram alerts**. This project reminds the user to take medicine at scheduled times and sends a notification message to a Telegram chat.

---

## ✨ Features

* Displays real-time clock using DS3231 RTC
* Set **two separate daily reminders** using physical buttons
* Sends **Telegram notification** when it's time to take medicine
* Buzzer alarm until detected by IR sensor
* OLED display shows system status, reminder times, and current time
* Simple 3-button interface for adjusting reminders
* WiFi-enabled alerts with secure HTTPS communication

---

## 🧠 How It Works

1. The ESP32 connects to WiFi and initializes the RTC and OLED display.
2. You can switch between Reminder 1 and Reminder 2 using the `Switch` button.
3. The `Hour` and `Minute` buttons let you set the desired reminder time.
4. When the current time matches a set reminder:

   * A Telegram alert is sent.
   * The buzzer turns ON.
5. When the IR sensor detects a hand inside the medicine box, the buzzer turns OFF.
6. Each reminder resets automatically for the next day.

---

## 📁 Project Folder Structure

```
Medicine-Reminder-Box/
│
├── README.md                # Main project documentation
├── components.md            # Components list
├── wiring.md                # Wiring connections table
├── images/                  # Photos of project 
│   ├── circuit-diagram.png
│   ├── final-setup.jpg
│
└── src/
    └── Medicine_Box_Code.ino   # Arduino/ESP32 code
```

---

## 🔧 How to Upload the Code to ESP32

1. Install **Arduino IDE**.
2. Add ESP32 Board Manager URL:

   * `File` → `Preferences`
   * Add this to *Additional Board URLs*:

     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
3. Install **ESP32 board package**:

   * Tools → Board → Boards Manager → search "ESP32" → Install
4. Install required libraries:

   * Adafruit SSD1306
   * Adafruit GFX
   * RTClib
5. Connect your ESP32 via USB.
6. Select board:

   * Tools → Board → `ESP32 Dev Module`
7. Select the correct port:

   * Tools → Port → COMx (Windows) / /dev/ttyUSBx (Linux)
8. Open the `.ino` file from the `src` folder.
9. Hit **Upload**.

---

## 🌐 Setting Up WiFi & Telegram Alerts

### 1. Set your WiFi name and password

In the code, locate this section:

```
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
```

Replace them with your real credentials.

### 2. Create a Telegram Bot

1. Open Telegram
2. Search for **BotFather**
3. Type `/newbot`
4. Give your bot a name → username
5. BotFather gives you a **bot token** → Copy it
6. Paste into code:

```
const char* telegramBotToken = "YOUR_BOT_TOKEN";
```

### 3. Get Your Chat ID

1. Open Telegram
2. Search for **@userinfobot**
3. Type `/start`
4. Copy the shown chat ID
5. Put it in your code:

```
const char* chatID = "YOUR_CHAT_ID";
```

---

## 🚀 Future Improvements

* Add battery backup for portability
* Add mobile app for setting reminders
* Store reminder times in EEPROM
* Add multiple reminder slots beyond two
* Integrate speaker with custom tones
* Add vibration motor for silent alerts
* Add LCD keypad for easier input
* Create 3D-printed enclosure

---

## 👤 Author

**devbysour (Atharva)**
