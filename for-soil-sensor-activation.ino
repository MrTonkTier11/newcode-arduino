/*NOTE: ONLY REMOVE THE soilval != analogPin if you 
want to see the resistance value of the sensor

PS: yung mga "//" or dalawang forward slash, comment ko yun and di babasahin ng code
-- Ezekiel */



int analogPin = A0; //connect A0 pin from soil sensor doon sa A0 port or butas ng board niyo
int soilVal; // ito ung gagamitin na variable for the value ng soil sensor niyo
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(analogPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

soilVal = analogRead(analogPin); // ito ung line na para gumana ung soil sensor (analog values ang result)
/*if (soilval != analogPin){
  Serial.println("Soil_Value: ");
  Serial.println(soilVal);
}*/

// this if statement kapag nadetect na dry ung lupa
if (analogRead(0)>900){
  Serial.println("DRY!");
}

// this else statement kapag nadetect na basa or moist ang lupa
else{
  Serial.println("WET");
}
}
