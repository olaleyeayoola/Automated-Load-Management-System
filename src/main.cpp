#include <Arduino.h>
#include "supply.h"
#include "load.h"

char power_source = get_power_source();
int battery_level = get_battery_level();

void setup()
{
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:

  while (1)
  {
    switch (power_source)
    {
    case ('1'):
      //   Charge battery;
      turn_on_loads(1); // turn on emergency loads;
      turn_on_loads(2); // Turn on critical loads;
      turn_on_loads(3); // turn on non - critical loads;

    case ('2'):
      // full level battery;
      if (battery_level >= 50)
      {
        turn_on_loads(1); // turn on emergency loads;
        turn_on_loads(2); // Turn on critical loads;
        turn_on_loads(3); // turn on non - critical loads;
      }

      // half level battery
      if (battery_level < 50 && battery_level > 30)
      {
        turn_on_loads(1);  // turn on emergency loads;
        turn_on_loads(2);  // Turn on critical loads;
        turn_off_loads(3); // turn off non - critical loads;
      }

      // emergency level battery
      if (battery_level < 30 && battery_level > 15)
      {
        turn_on_loads(1);  // turn on emergency loads;
        turn_off_loads(2); // Turn off critical loads;
        turn_off_loads(3); // turn off non - critical loads;
      }

      // low level battery
      if (battery_level < 15 && battery_level > 5)
      {
        turn_off_loads(1); // turn off emergency loads;
        turn_off_loads(2); // Turn off critical loads;
        turn_off_loads(3); // turn off non - critical loads;
      }
      break;

    default:
      turn_off_loads(1); // turn off emergency loads;
      turn_off_loads(2); // Turn off critical loads;
      turn_off_loads(3); // turn off non - critical loads;
      break;
    }

    battery_level = get_battery_level();
    power_source = get_power_source();
  }
}