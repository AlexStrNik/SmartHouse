#include <TroykaDHT.h>

DHT dht(13, DHT11);

void initDHT(){
  dht.begin();
}

void printDataDHT(){
   dht.read();
   switch(dht.getState()) {
   case DHT_OK:
     Serial.print("Temperature = ");
     Serial.print(dht.getTemperatureC());
     Serial.println(" C \t");
     Serial.print("Humidity = ");
     Serial.print(dht.getHumidity());
     Serial.println(" %");
   break;
   case DHT_ERROR_CHECKSUM:
     Serial.println("Checksum error");
   break;
   case DHT_ERROR_TIMEOUT:
     Serial.println("Time out error");
   break;
   case DHT_ERROR_NO_REPLY:
     Serial.println("Sensor not connected");
   break;
  }
}
