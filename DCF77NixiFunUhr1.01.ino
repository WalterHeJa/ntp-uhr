
/*--------------------------------------
DCF77 - NIXI-Uhr
By Walter Helm -Eberbach,den 25.03.2015.
erstellt mit:
Arduino IDE Version 1.0.6
----------------------------------------*/

#include <Utils.h>
#include <Time.h>
#include <DCF77.h>
using namespace Utils;

#define DEBUG 1

#define DCF_PIN 2	         // Connection pin to DCF 77 device; hier kommt das DCF7-Signal an.
#define DCF_INTERRUPT 0		 // Interrupt number associated with pin

time_t prevDisplay = 0;          // when the digital clock was displayed
time_t time;
DCF77 DCF = DCF77(DCF_PIN,DCF_INTERRUPT);
unsigned long temp;
//int umschaltPin = 14;

void setup() {
  if (DEBUG == 1)
  { 
    Serial.begin(9600);
    Serial.println("ProgrammStart"); 
  }
  DCF.Start();
  setSyncInterval(30);
  setSyncProvider(getDCFTime);
  
 
  pinMode(3, OUTPUT);            //LSB; Pin 3 - 6 ist 4-bit Binaerausgabe für Einer
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
  
  pinMode(7, OUTPUT);            //MSB; Pin 7 -10 ist 4-bit Binärausgabe für Zehner
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
    
  pinMode(11, OUTPUT);           // LE Seconds, Year;  Pin 11 ist Enableausgang an Latch für Sekunen und Jahranzeige     
  pinMode(12, OUTPUT);           // LE Minute,  month; Pin 12 ist Enableausgang an Latch für Minuten und Monatanzeige
  pinMode(13, OUTPUT);           // LE Hour,    day;   Pin 13 ist Enableausgang an Latch für Stunden und Tagesanzeige
  //pinMode(A0, OUTPUT);
  
  }

void loop()
{
  if( now() != prevDisplay)       /*Die Anzeige wird Aktualisiert wenn die Uhrzeit wechselt*/
  {
    prevDisplay = now();
    displayAnzeige(); 
  } 
}

void digitalClockDisplay(){        //Anzeige der Uhrzeit

  
    ausgabeEiner(hour());
    ausgabeZehner(hour());
  digitalWrite(13, HIGH);      // Enable für Sekunden
  digitalWrite(13, LOW);        // Enable ausschalten

  
 
    ausgabeEiner(minute());
    ausgabeZehner(minute());
  digitalWrite(12, HIGH);       // Enable für Minuten
  digitalWrite(12, LOW);        // Enable ausschalten
 
 
 
    ausgabeEiner(second());
    ausgabeZehner(second());
  digitalWrite(11, HIGH);       // Enable für Stunden
  digitalWrite(11 , LOW);        // Enable ausschalten 
  
}

void digitalDateDisplay(){      // Anzeige des Datums

  
    ausgabeEiner(day());
    ausgabeZehner(day());
  digitalWrite(13, HIGH);      // Enable für Sekunden
  digitalWrite(13, LOW);        // Enable ausschalten

  
 
    ausgabeEiner(month());
    ausgabeZehner(month());
  digitalWrite(12, HIGH);       // Enable für Minuten
  digitalWrite(12, LOW);        // Enable ausschalten
 
 
 
    ausgabeEiner(year());
    ausgabeZehner(year());
  digitalWrite(11, HIGH);       // Enable für Stunden
  digitalWrite(11 , LOW);        // Enable ausschalten 
  
}

unsigned long getDCFTime()
{
  time_t DCFtime = DCF.getTime();
  /*digitalWrite(A0,LOW);
  //Indicator that a time check is done*/
  if (DCFtime!=0)
  /*{
    //digitalWrite(A0, HIGH); 
  }
  else{
    digitalWrite(A0, LOW);
  }*/
  return DCFtime;
}




