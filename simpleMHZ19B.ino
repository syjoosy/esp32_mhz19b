//
// MHZ19B
//

#include <MHZ19_uart.h>

MHZ19_uart mhz19;

#define MHZ_RX 18
#define MHZ_TX 17

int co2;

void setup() {
  Serial.begin(9600);
 
  mhz19.begin(MHZ_TX, MHZ_RX);
  mhz19.setAutoCalibration(false);
  mhz19.getStatus();
  //mhz19.calibrateZero();
  delay(2000);
  if (mhz19.getStatus() == -1)
    Serial.println("MHZ19 ERROR");
  else
    Serial.println("MHZ19 OK");

}

uint32_t timer;
void loop() 
{
  if (millis() - timer > 5000)
  {
    timer = millis();
    co2 = mhz19.getPPM();
    Serial.print("CO2: ");
    Serial.print(co2);
    Serial.println("ppm");
  }
}
