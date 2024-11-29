#include <DHT11.h>
#include <LiquidCrystal_I2C.h>

DHT11 dht11(2);
//An instance of dht11 connected to digital pin 2

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.init(); // initializes the lcd
lcd.backlight(); //turns on the backlight
}

void loop() {
  // put your main code here, to run repeatedly:
  int temperature = 0;
  int humidity = 0;

int result = dht11.readTemperatureHumidity(temperature, humidity);//method to read the temperature and humidity
if (result == 0){
lcd.setCursor(0,0);
lcd.print("Temperature: ");
lcd.print(temperature);
lcd.setCursor(0, 1);
lcd.print("Humidity: ");
lcd.print(humidity);
delay(1000);

}
else{
  lcd.print(DHT11::getErrorString(result));
}
}
