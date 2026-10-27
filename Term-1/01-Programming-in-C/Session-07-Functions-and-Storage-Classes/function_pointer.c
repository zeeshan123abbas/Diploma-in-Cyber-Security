#include <stdio.h>

int add(int a, int b)      { return a + b; }
int multiply(int a, int b) { return a * b; }

int main(void)
{
    int choice;
    int (*operation)(int, int);     // pointer to a function taking two ints

    printf("1) add  2) multiply: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1)
        operation = add;            // point at add
    else
        operation = multiply;       // point at multiply

    printf("Result for 6 and 7: %d\n", operation(6, 7));
    return 0;
}
