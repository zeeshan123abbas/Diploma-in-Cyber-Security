#include <stdio.h>

int main(void)
{
    int a = 5, b = 9, temp;

    temp = a;    // keep a safe
    a = b;       // a gets b
    b = temp;    // b gets old a

    printf("a = %d, b = %d\n", a, b);
    return 0;
}
