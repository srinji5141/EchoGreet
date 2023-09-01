#include <LiquidCrystal.h> // Includes the LiquidCrystal Library 
LiquidCrystal lcd(3, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
const int microphonePin = A0;

void loop() {

  int mn = 1024;
  int mx = 0;
  for (int i = 0; i < 10000; ++i) {
    int val = analogRead(microphonePin);
    mn = min(mn, val);
    mx = max(mx, val); // Reads in min, max analogue values
  }

  int delta = mx - mn; // Computes delta and checks condition for clap
  if (delta > 220) { 
    lcd.clear(); // Clears the display  

    char* string_to_print = "Hello, World!";
    for (char* p = string_to_print; *p != '\0'; p ++) { 
      lcd.print(*p);
      delay(200); // Prints each char in string with 200ms delay
    } 
  }
}

void setup() { 
  Serial.begin(9600);
  lcd.begin(16,2); // Initializes the interface to the LCD greeting panel, and specifies the dimensions (width and height) of the display  
  lcd.clear(); // Clears the display  
}
