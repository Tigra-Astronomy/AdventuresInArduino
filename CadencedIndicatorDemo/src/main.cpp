#include <Arduino.h>
#include <CadencedIndicator.h>

namespace Cadence 
{
  constexpr CadencePattern SOS = 0b10101000111011101110001010100000ul;
}

CadenceManager ledManager;
Indicator builtInLed(LED_BUILTIN, Cadence::Heartbeat | Cadence::Offbeat);
Indicator externalBlueLed(2, Cadence::Wink);
Indicator externalRedLed(3, Cadence::Blip);
Indicator externalGreenLed(4, Cadence::SOS);

void setup()
{
  // put your setup code here, to run once:
  ledManager.addIndicator(builtInLed);
  ledManager.addIndicator(externalBlueLed);
  ledManager.addIndicator(externalRedLed);
  ledManager.addIndicator(externalGreenLed);
}

void loop()
{
  // put your main code here, to run repeatedly:
  ledManager.loop();
}