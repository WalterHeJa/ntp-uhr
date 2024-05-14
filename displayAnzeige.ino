/*--------------------------------------
Umschalten Datum - Uhrzeit.
By Walter Helm -Eberbach,den 25.03.2015.
Arduino IDE Version 1.0.6
----------------------------------------*/
/*unsigned long temp;
int umschaltPin = 14;*/

void displayAnzeige()
{
  if (DEBUG == 1)
  {
    Serial.print(millis());
    Serial.println(" -> umschaltDisplay ausgefuehrt");
  }
  //Serial.begin(9600);
  //pinMode(umschaltPin, INPUT);
  //int umschaltState = LOW;
  temp = millis()/10000;
  //Serial.println(temp);
  //umschaltState = digitalRead(umschaltPin);
  //Serial.println(umschaltState);
  temp = temp & 1;
  if (temp == 0) //|| (umschaltState == HIGH)
  {
    digitalClockDisplay();
  }
  else
  {
    digitalDateDisplay();
  }
  //delay(100);
}


