#include <Arduino.h>

struct Loads
{
    int pin_no;
    int start_time;
    int end_time;
    int priority;
};

Loads load1 = {12, 1230, 1245, 1};
Loads load2 = {13, 1330, 1445, 1};

Loads all_loads[2] = {load1, load2};

void turn_on_loads(int priority)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        Loads ld = all_loads[i];
        if (ld.priority == priority)
        {
            digitalWrite(ld.pin_no, HIGH);
        }
    }
}

void turn_off_loads(int priority)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        Loads ld = all_loads[i];
        if (ld.priority == priority)
        {
            digitalWrite(ld.pin_no, LOW);
        }
    }
}