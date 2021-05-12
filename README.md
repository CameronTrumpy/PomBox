# PomBox
**Arduino Software for ESP-8266 based productivity timer**

This readme details how to make your own pombox.

## 1. Gather your Parts

 - [16x2 LCD](https://www.sparkfun.com/products/16397) from Sparkfun
 - [Mini Speaker](https://www.sparkfun.com/products/7950) from Sparkfun
 - [At least one set of Buttons](https://www.sparkfun.com/products/15326) from Sparkfun
 - [Breadboard](https://www.sparkfun.com/products/12615) from Sparkfun
 - Any [ESP-8266](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010O1G1ES) or similar form factor Arduino/Carrier Board

## 2. Setup your Arduino project
 If you have not worked with Arduino or an ESP-8266 board, you will need to set up your Arduino IDE and your libraries.
 Follow through the steps below if you need help setting up your Arduino IDE with an ESP-8266.

1.**Download and install the Arduino IDE**
Download either the latest version of the classic IDE, or try out the new 2.0 IDE which is in its beta stages right now, at the [Arduino website](https://www.arduino.cc/en/software).

2.**Add ESP-8266 Libraries**
Once installed, go to `File -> Preferences` in the navigation menu. Enter the URL "http://arduino.esp8266.com/stable/package_esp8266com_index.json” into Additional Board Manager URLs field and click the “OK” button.
 
## 3. Testing your Arduino
 Try running the example blink program, and make sure it runs well.

## 4. Assembling your PomBox

## 5. Ideas for Further Improvements
 -Try designing your own housing, or 3D printing your own. [I included a basic STL](https://github.com/CameronTrumpy/PomBox/model) that I put together for mine.
 -Add custom controls
 -Beautify the GUI/Menus on the LCD
