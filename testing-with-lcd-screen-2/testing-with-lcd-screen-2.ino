#include <LCD_I2C.h>
#include <DHT11.h>
LCD_I2C lcd(0x27, 16, 2);
DHT11 dht11(3);

int temp;
int humid;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp = dht11.readTemperature();
  humid = dht11.readHumidity();
  if (temp != DHT11::ERROR_CHECKSUM && temp != DHT11::ERROR_TIMEOUT){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TEMP:");
    lcd.setCursor(6, 0);
    lcd.print(temp);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("HUMID:");
    lcd.setCursor(7,7);
    lcd.print(humid);
    lcd.print("%");
    Serial.print(temp);
    Serial.println("°C");
    delay(1000);
  }

  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(DHT11::getErrorString(temp));
    Serial.print(DHT11::getErrorString(temp));
  }
}
