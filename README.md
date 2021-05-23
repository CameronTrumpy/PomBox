# PomBox
**Arduino Software for ESP-8266 based productivity timer**
Details on how to make your own pombox.

## 1. Gather your Parts

 - [16x2 LCD](https://www.sparkfun.com/products/16397) from Sparkfun
 - [Mini Speaker](https://www.sparkfun.com/products/7950) from Sparkfun
 - [At least one set of Buttons](https://www.sparkfun.com/products/15326) from Sparkfun
 - [Breadboard](https://www.sparkfun.com/products/12615) from Sparkfun
 - Any [ESP-8266](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010O1G1ES) or similar form factor Arduino/Carrier Board
 - Multiple colors of solid core wire for breadboard wiring

## 2. Setup your Arduino IDE
 If you have not worked with Arduino or an ESP-8266 board, you will need to set up your Arduino IDE and your libraries.
 Follow through the steps below if you need help setting up your Arduino IDE with an ESP-8266.

1.**Download and install the Arduino IDE**
Download either the latest version of the classic IDE, or try out the new 2.0 IDE which is in its beta stages right now, at the [Arduino website](https://www.arduino.cc/en/software).

2.**Add ESP-8266 Libraries**
Once installed, go to `File -> Preferences` in the navigation menu. Enter the URL "http://arduino.esp8266.com/stable/package_esp8266com_index.json" into Additional Board Manager URLs field and click the “OK” button.

Later on, you will need the SerLCD library from Sparkfun, if you are using the 16x2 LCD that was listed above. To add this library, download the [latest relased zip](https://github.com/sparkfun/SparkFun_SerLCD_Arduino_Library/releases).
Once downloaded, go to `Sketch -> Include Library -> Add .ZIP library`, and select the library you downloaded.

3.**Select your Board**
Select your model board on `Tools -> Board`, and once your board is connected to your PC, select the correct USB device in `Tools -> Port`.

## 3. Testing your Arduino
Try running the example blink program located at `File -> Examples -> ESP8266 -> Blink`.

## 4. Assembling your PomBox
This step leaves room for lots of experimentation on your own, I encourage you to figure out what works the best for your setup. Here is a pinout table from my esp to the rest of my buttons. The rest of the wiring is easy to figure out, and is mainly just jumper wiring ground to your buttons and across the board. 

Wiring Table
| ESP PINS- FROM | GPIO #  | TO position              |
|----------------|---------|--------------------------|
| 3V3            |   n/a   | RAW serLCD               |
| GND            |   n/a   | (-) serLCD               |
| 3V3            |   n/a   | (+) breadboard rail      |
| GND            |   n/a   | (-) breadboard rail      |
| D1             |   n/a   | SCL - serLCD             |
| D2             |   n/a   | SDA - serLCD             |
| D3             |    0    | Confirm(Green) Button +  |
| D5             |    14   | Alarm +                  |
| D6             |    12   | Trigger(Yellow) Button + |
| D7             |    13   | Cancel(Red) Button +     |
| SD3            |    10   | Up(Blue) Button +        |

You will notice in the image below that I soldered my wired to the LCD. Please note that I did not have enough variety of wire colors to designate any color to a specific meaning. For example, I have Black wires running for GND and also for some buttons (+) sides. This is not a good practice and should be avoided to ensure that wire colors accurately correspond to their conventional meanings.

<img src="/Res/top.jpg" alt="Wiring View" width="500"/>

[I included a basic STL case](https://github.com/CameronTrumpy/PomBox/tree/main/Model) that I put together for mine. Design your own or download the one I made!

<img src="/Res/front.jpg" alt="Front of Box" width="500"/>

## 5. Upload the Project
To upload the full PomBox project to your Arduino, each file needs to be loaded into your Arduino Project separately.
Start by going to `File -> Open` and open the `pombox.ino` file, from wherever you cloned the repository to.

Once you load this in, you will need to add the rest of the files. To do so, you need to navigate to `Sketch -> Add File`, then select the rest of the `.ino` files from the cloned repository.

## 6. Ideas for Further Improvements
 - Try designing your own housing
 - Add custom controls
 - Beautify the GUI/Menus on the LCD
 - Upgrade from breadboard design to perfboard or a more permanent and robust solution
