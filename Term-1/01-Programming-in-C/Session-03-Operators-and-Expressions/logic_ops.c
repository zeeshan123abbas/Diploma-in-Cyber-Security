#include <stdio.h>

int main(void)
{
    int length = 10;        // password length
    int hasDigit = 1;       // 1 = yes, 0 = no
    int hasSymbol = 0;

    int strong = (length >= 8) && hasDigit && hasSymbol;
    int okay   = (length >= 8) && (hasDigit || hasSymbol);

    printf("Strong: %d\n", strong);   // 0
    printf("Okay  : %d\n", okay);     // 1
    printf("Not strong: %d\n", !strong);
    return 0;
}
