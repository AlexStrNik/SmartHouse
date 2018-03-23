#include <TroykaDHT.h>
#include <QuadDisplay2.h> 

char* pstdstr;

DHT dht(11, DHT11);
QuadDisplay quad(12);
#define PWMOUT 44

void setup(){
  char* dispData[32];
  pstdstr = &dispData[0];
  Serial.begin(19200);
  pinMode(A0, INPUT);
  dht.begin();
}

void workPWM(int value, int data){
    int num = 256 * (1 - ((data - value) / data));
    analogWrite(PWMOUT, num);
}

void workQD(unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char arg4){
  quad.displayClear();
  quad.displayDigits(arg1, arg2, arg3, arg4);
}

void dhtDataPrint(){
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

int workLS(){
  return analogRead(A0);
}

void loop(){
  dhtDataPrint();
  workPWM(dht.getTemperatureC(), 10);
  Serial.println(workLS);
  delay(2000);
}
