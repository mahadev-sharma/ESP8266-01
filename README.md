# Introduction

This respository contains various projects and ways to develop stand alone systems with the ESP 8266-01.  The target platform can be either linux, windows, Esplorer, ESptool.  You can find few complete projects with circuit diagram and full code that is written below.

# Materials

This project is developed and researched around ESP8266 - 01  wifi module, here are some of the parts used to build this project:

Things used in this project:

- Jumper wires
- LED
- Resistors(For LED)
- Push button
- ESP8266-01
- Multimeter
- Ceramic Capacitor
- Electrolytic Capacitor
- Breadboard
- 3.3V converter
- USB to TTL

# Troubleshooting

You can find a number of screenshots that show some common errors in the 'screenshots' directory.  For most of them, the solution to the problem is described by the filename of the screenshot.

# Algorithm 1: Deep Sleep Mode

I tried exploring edge cases of ESP 8266 - 01 with deep sleep mode.  I can calculated power consumption and tried to use battery power for a long time.

How it works:

- First of install Arduino IDE
- Install ESP8266 - 01 libraries in Arduino IDE
- Make developing board for ESp 8266 01
- Install deep sleep mode code in ESP6266 - 01
- Check power consumption in different modes by multimeter 
- Ready to rock and roll
- See in Action

#  Algorithm 2: GPIO Controlling On Secured Wifi Network

You will need:
 
- Jumper wires
- LED
- Resistors(For LED)
- Push button
- ESP8266-01
- Ceramic Capacitor
- Electrolytic Capacitor
- Breadboard
- 3.3V converter
- USB to TTL

I tried to using GPIO control using secured wifi network using the customized app.

How it works:

- First of install Arduino IDE
- Install ESP8266 - 01 libraries in Arduino IDE
- Make developing board for ESp 8266 01
- Install secured wifi network code in ESP6266 - 01
- Add HTML and CSS code to make App more beautiful
- Ready to rock and roll
- See it in Action.

#  Algorithm 3: GPIO controlling by website

You will need:
 
- Jumper wires
- LED
- Resistors(For LED)
- Push button
- ESP8266-01
- Ceramic Capacitor
- Electrolytic Capacitor
- Arduino
- Arduino Cable
- STM32 Discovery Board
- STM32 Discovery board power cable
- Relay
- Breadboard
- 3.3V converter
- USB to TTL


I tried using GPIO control using secured customized website.

How it works:

- First of install Arduino IDE
- Install ESP8266 - 01 libraries in Arduino IDE
- Control ESP8266 - 01 with Arduino board
- Load the Arduino with code of wifi and website credentials
- Save the PHP code on server side
- Load the relay controlling code in STM32 Discovery board
- Add bootstrap and CSS code to make website more beautiful
- Ready to rock and roll
- See it in Action.


#  Algorithm 4: Dallas Temperature Monitor

You will Need:
 
- Jumper wires
- LED
- Resistors(For LED)
- Push button
- ESP8266-01
- Ceramic Capacitor
- Electrolytic Capacitor
- Dallas Temperature sensor
- Breadboard
- 3.3V converter
- USB to TTL
- DTH 11 temperature and humidity sensor


I tried using the ESP 8266 - 01 with a Dallas temperature sensor that can report from time to time as per our requirements.  It's three-pin digital sensor.

How it works:

- First of install Arduino IDE
- Install ESP8266 - 01 libraries in Arduino IDE
- Make developing board for ESp 8266 01
- Load the ESP8266 - 01 with correct credential of wifi
- Interface ESP8266 - 01 with Dallas temperature sensor on GPIO 0
- Make graph of temperature
- Ready to rock and roll

#  Algorithm 5: Weather station

You will Need:
 
- Jumper wires
- LED
- Resistors(For LED)
- Push button
- ESP8266-01
- Ceramic Capacitor
- Electrolytic Capacitor
- Dallas Temperature sensor
- Breadboard
- 3.3V converter
- USB to TTL
- DTH 11 temperature and humidity sensor
 
I also tried exploring using the ESP 8266-01 with DTH11 temperature and humidity sensor that can report time to time as per our requirements.  It's 4 pin sensor.  Observe the data graph on think speak is really convenient.

How it works:

- First of install Arduino IDE
- Install ESP8266 - 01 libraries in Arduino IDE
- Make developing board for ESp 8266 01
- Load the ESP8266 - 01 with correct credential of wifi
- Interface ESP8266 - 01 with DTH11 sensor on GPIO 0
- Connect with Thinkspeak.com
- Make graph of temperature and humidity
- Analyse and store data on website
- By combining GPIO controlling using internet  and this code we can make home automation easily
- Ready to rock and roll
- See in Action.


For more details:- http://mahadev-com.stackstaging.com/
