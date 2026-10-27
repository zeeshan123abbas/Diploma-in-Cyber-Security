#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Enter two whole numbers: ");
    if (scanf("%d %d", &a, &b) != 2) {     // check input was valid
        printf("Invalid input.\n");
        return 1;
    }

    printf("Sum        = %d\n", a + b);
    printf("Difference = %d\n", a - b);
    printf("Product    = %d\n", a * b);
    if (b != 0) {                           // never divide by zero
        printf("Quotient   = %d\n", a / b);
        printf("Remainder  = %d\n", a % b);
        printf("Exact      = %.2f\n", (double)a / b);
    }
    return 0;
}
