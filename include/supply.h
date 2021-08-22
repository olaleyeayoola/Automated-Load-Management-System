#include <stdio.h>
#include <string.h>

char pw_source = '2';
int batt_level = 100;

char get_power_source()
{
    return pw_source;
}

int get_battery_level()
{
    return batt_level;
}