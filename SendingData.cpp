// Get and send temperature data from temperature sensor to ThingSpeak
#include <Adafruit_DHT.h>

DHT dht(D4, DHT22); //(pin, model)

void setup() {
    Serial.begin(9600); //set the analog rate?
    dht.begin(); //start reading data from the DHT22
}

void loop() {
    delay(30000);
    String temp = String(dht.getTempCelcius()); //Get temperature from DHT22
    Particle.publish("temp", temp, PRIVATE); //Publish temp data to ThingSpeak
}
