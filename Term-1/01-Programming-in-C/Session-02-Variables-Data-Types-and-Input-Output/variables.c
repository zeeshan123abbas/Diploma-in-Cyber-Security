#include <stdio.h>

int main(void)
{
    int    port   = 443;       // whole number
    float  uptime = 99.9f;     // decimal number
    char   grade  = 'A';       // single character

    printf("Port   : %d\n", port);
    printf("Uptime : %.1f%%\n", uptime);   // %% prints a percent sign
    printf("Grade  : %c\n", grade);

    printf("int uses %zu bytes\n", sizeof(int));
    printf("double uses %zu bytes\n", sizeof(double));
    return 0;
}
