#include <stdio.h>

void swapByValue(int a, int b)       // gets copies
{
    int t = a; a = b; b = t;
    (void)a; (void)b;                // copies change, then are thrown away
}

void swapByReference(int *a, int *b) // gets addresses
{
    int t = *a; *a = *b; *b = t;
}

int main(void)
{
    int x = 1, y = 2;
    swapByValue(x, y);
    printf("After by value    : x=%d y=%d\n", x, y);   // 1 2
    swapByReference(&x, &y);
    printf("After by reference: x=%d y=%d\n", x, y);   // 2 1
    return 0;
}
