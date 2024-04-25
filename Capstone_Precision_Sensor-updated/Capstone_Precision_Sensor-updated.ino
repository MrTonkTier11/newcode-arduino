// patnggal nalang ng mga "//" (mostly sa lcd kasi ung iba) para magamit niyo if want niyo  -- Ezekiel
#define SMP A0
#define RP 2
//#include <LCD_I2C.h>
//LCD_I2C lcd(0x27, 16, 2);
int percentage;
int ML;

void setup() {
  Serial.begin(9600);
  //lcd.begin();
  //lcd.backlight();
  //lcd.setCursor (0,0);
  //lcd.print("Soil Moisture:");
  pinMode(SMP, INPUT);
  pinMode(RP, OUTPUT);
  digitalWrite(RP, LOW);
}

void loop () {
  ML = analogRead(SMP);
  percentage = map(ML, 0, 1023, 100, 0); // binalik ko sa dati ung mapping kasi pag dry naigging 100, we don't want that, dapat either 0 or 1 ung level niya and pag moist mga nataas greater than 1
  //lcd.setCursor(0, 1);
  //lcd.print(percentage);
  //Serial.println(ML);
  Serial.println(percentage);
  if (ML > 900){
    digitalWrite(RP, HIGH);
    Serial.println("DRY");
    delay(1000);
  }
  else if(ML < 900){
    digitalWrite(RP, LOW);
    Serial.println("WET");
    delay(1000);
  }
  }