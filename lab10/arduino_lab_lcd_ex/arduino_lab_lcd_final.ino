/*
  LiquidCrystal Library - Serial Input

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch displays text sent over the serial port
  (e.g. from the Serial Monitor) on an attached LCD.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009
  by Tom Igoe
  modified 22 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalSerial
*/

// include the library code:
#include <LiquidCrystal.h>
#include <avr/interrupt.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28);
int __counter = 0;
long _hour = 0;
long _min = 0;
long _sec = 0;
int num = 0;
bool time_set = false;
bool paused = false;


//arduino runs the setup function first, then the loop function below
void setup() {
  pinMode(24, OUTPUT); //K
  pinMode(26, OUTPUT); //A
  pinMode(54, OUTPUT); //VSS
  pinMode(52, OUTPUT); //VDD
  pinMode(50, OUTPUT); //Contrasty pin

  // digitalWrite(50, LOW);
  digitalWrite(24, LOW); //Backlight
  digitalWrite(26, HIGH); //Backlight
  digitalWrite(54, LOW); //GND
  digitalWrite(52, HIGH); //VDD
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
  // Timer0 is used for millis() - we'll just interrupt
  // in the middle and call the compA
  OCR0A = 0x01;
  TIMSK0 |= _BV(OCIE0A);
}

SIGNAL(TIMER0_COMPA_vect) 
{
   __counter++;
   if (__counter > 14){
      digitalWrite(50,HIGH);
      __counter = 0;
   }
   else if (__counter > 3){
      digitalWrite(50, LOW);
   }
}

//Here is where your code goes. Arduino runs this function in an infinite loop after running the setup function
void loop() {
  
  //return cursor to starting position
  lcd.home();

  //clear the lcd screen
  lcd.clear();

  String message = Serial.readString();// read a string sent from the computer

  if( message.equalsIgnoreCase("stop") )
  {
    paused = true;  
  }
  if( message.equalsIgnoreCase("start") )
  {
    paused = false;  
  }  
  if( message.length() == 4 && message[0] == 't' )
  {
    _hour = message[1] - '0';
    _min = (message[2] - '0')*10 + (message[3] - '0');
    _sec = 0;
    time_set = true;
    paused = false;
  }
  else if( message.length() == 5 && message[0] == 't' ) 
  {
    _hour = (message[1] - '0')*10 + (message[2] - '0');
    _min = (message[3] - '0')*10 + (message[4] - '0');
    _sec = 0;
    time_set = true;
    paused = false;
  }

  if(!time_set )
  {
    _hour = 12;
    _min  = 0;
    _sec  = 0;
  }
  lcd.print("Current time:");
  lcd.setCursor(0, 1);
  lcd.print(_hour);
  lcd.print(":");
  lcd.print(_min);
  lcd.print("::");
  lcd.print(_sec);
  
  //sets the x,y position of the cursor. In this case we move the cursor to the second line.
  //lcd.setCursor(0, 1);
  //lcd.print("Num: ");
  //lcd.print(num);
  //++num;

  //sleep for .5 second
  delay(500);
  if(! paused)
  {
    ++_sec;
  }
  //check for overflow
  if( _sec >= 60 )
  {
    _sec = 0;
    ++_min;
  }
  if( _min >= 60 )
  {
    _min = 0;
    ++_hour;
  }
  if( _hour >= 13 )
  {
    _hour = 1;
  }
}


