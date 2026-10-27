#include <stdio.h>

int main(void)
{
    int a, b;                       // two whole-number boxes

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);         // read both numbers

    if (a > b)                      // decision diamond
        printf("Larger is %d\n", a);
    else
        printf("Larger is %d\n", b);

    return 0;
}
