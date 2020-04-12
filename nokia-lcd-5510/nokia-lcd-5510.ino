#include <SDHT.h>
#include <Nokia_LCD.h>

// https://platis.solutions logo with vertically oriented bytes.
// The bitmap was generated via the `LCD Assistant` utility.


Nokia_LCD lcd(13 /* CLK */, 11 /* DIN */, 5/* DC */, 7/* CE */, 6 /* RST */);
SDHT dht;

void setup() {
  Serial.begin(115200);

  // Initialize the screen
  lcd.begin();
  // Set the contrast
  lcd.setContrast(60);  // Good values are usualy between 40 and 60
  // Clear the screen by filling it with black pixels
  lcd.clear(true);
  //delay(2000);
  // Draw the platis.solutions logo on your screen
  //lcd.draw(platis_solutions_logo,
  //         sizeof(platis_solutions_logo) / sizeof(platis_solutions_logo[0]),
  //         true);
  //delay(3000);
  // Clear the screen by filling it with white pixels
  lcd.clear();
}

void loop() {
  layout();
  //delay(5000);
  lcd.clear();
}
int i = 0;
void layout() {  
  if (dht.read(DHT11, 2)) {
    lcd.setCursor(0, 0);

    lcd.print("Temp : ");
    float celcius = dht.celsius / 10.0;
    lcd.print(String(celcius, 2).c_str());
    const unsigned char bitmap[5] = {0x00, 0x07, 0x05, 0x07, 0x00} ;
    lcd.print(" ");
    lcd.draw(bitmap, 5, false);
    lcd.print("C");
    lcd.println("");
    //lcd.print("F.heit  : ");
    float fahrenheit = (celcius * 9 / 5) + 32;
    //lcd.println(String(fahrenheit, 2).c_str());
    lcd.print("RH   : ");
    float humidity = dht.humidity / 10.0;
    lcd.print(String(humidity, 2).c_str()); 
    lcd.print("  %");   
    delay(5000);
  }
}
