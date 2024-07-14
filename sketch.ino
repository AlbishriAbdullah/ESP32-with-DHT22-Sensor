#include "DHT.h"

#define DHTPIN 4     
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT22 sensor test!");
}

void loop() {
  delay(5000);

  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check for the errors
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read data from DHT sensor!!!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print(f);
  Serial.print("°F  Heat index: ");
  Serial.print(hic);
  Serial.print("°C ");
  Serial.print(hif);
  Serial.println("°F");
}
