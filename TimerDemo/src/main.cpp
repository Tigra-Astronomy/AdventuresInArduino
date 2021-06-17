#include <Arduino.h>
#include <Timer.h>

Timer ledToggle;
const Duration ledToggleInterval(Timer::Seconds(0.5));
bool ledState = false;

void setup() {
  // put your setup code here, to run once:
  ledToggle.setDuration(ledToggleInterval);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ledToggle.expired())
  {
    ledToggle.setDuration(ledToggleInterval);
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
  }
}