#include <stdio.h>

void logEvent(void)
{
    static int count = 0;   // created once, keeps its value
    int temp = 0;           // auto: fresh every call
    count++; temp++;
    printf("event #%d (temp=%d)\n", count, temp);
}

int main(void)
{
    logEvent(); logEvent(); logEvent();
    return 0;
}
