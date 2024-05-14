       

void ausgabeEiner(int wert) {    // Ausgabe der Einer-Stellen an Pin 3 ..6
  int temp = wert % 10;
  digitalWrite(3, temp & 1);
  digitalWrite(4, temp & 2);
  digitalWrite(5, temp & 4);
  digitalWrite(6, temp & 8);
}

void ausgabeZehner(int wert)     // Ausgabe der Zehner-Stellen an Pin 7..10
{    
  int temp2 = 0;
  if (wert > 100)
  {
    temp2 = wert - 2000;
  }
  else
  {
    temp2 = wert;
  }
  
  int temp = temp2 / 10;         
  digitalWrite(7, temp & 1);
  digitalWrite(8, temp & 2);
  digitalWrite(9, temp & 4);
  digitalWrite(10, temp & 8);
} 

/*
void ausgabeEinerJahre(int wert) {    // Ausgabe der Einer-Stellen an Pin 3 ..6
  int temp = wert % 10;
  digitalWrite(3, temp & 1);
  digitalWrite(4, temp & 2);
  digitalWrite(5, temp & 4);
  digitalWrite(6, temp & 8);
}


void ausgabeZehnerJahre(int wert) {    // Ausgabe der Zehner-Stellen an Pin 7..10
  
  int temp = wert % 100;
  temp = temp / 10;  
  digitalWrite(7, temp & 1);
  digitalWrite(8, temp & 2);
  digitalWrite(9, temp & 4);
  digitalWrite(10, temp & 8);
} 


void digitalloeschen() {    // Ausgabe der Zehner-Stellen an Pin 7..10
  
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);  
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
} 
