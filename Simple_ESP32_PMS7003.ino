#include "PMS.h"
#include <Wire.h>

HardwareSerial SerialPMS(1);
PMS pms(SerialPMS);
PMS::DATA data;

#define RXD2 34
#define TXD2 36


void setup()
{
  Serial.begin(9600);
  SerialPMS.begin(9600, SERIAL_8N1, RXD2, TXD2);
  pms.passiveMode();

}

void loop()
{
  pms.wakeUp();
  delay(30000);
  pms.requestRead();


  if (pms.readUntil(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);
    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);
    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);
  }
  else
  {
    Serial.println("No data.");
  }
  pms.sleep();
  delay(60000);
}
