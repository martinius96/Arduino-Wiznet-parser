# Arduino Ethernet shield parser
# Support me for more examples
* https://www.paypal.me/Chlebovec

# What is parsing variable?
* Simple read what is inside of file (.txt, .html, .php, .json)

# Where to use?
* Home automatization
* Read commands --> Turn on light, Turn off light, Close door, Beep, etc for Voice control.
* Control outputs
* Read important informations/events

# Compatible Hardware
* Ethernet shield/module Wiznet W5100/W5200/W5300/W5500
* Each Arduino with SPI bus

# How it works?
* Every time you connect in client mode to website, you will get response from webserver
* In response are informations about website, engine, important informations and at least our information/variable that we want to read
* We only just need to read true row
* Normal response is most from 10-14 rows. 
* You need to set this parameter to Arduino code!

# Test sketches
* Test sketches connecting to my website https://arduino.php5.sk on HTTP protocol
* My website take 12 rows response before my variable (HTTP response lenght)

# Change parameter of variable
* Count the rows of the received response after the variable you want to read. Do not count the variable row!
![the image alt](https://i.nahraj.to/f/1ZOs.jpg)
* Change this number in code else if (x==12) readString += c; //for 12
* In test sketches we read "Zapni" or "Vypni" variable. Now we can use them in if statement! :-)
* Enjoy
