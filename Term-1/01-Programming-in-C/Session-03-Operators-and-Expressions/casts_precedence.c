#include <stdio.h>

int main(void)
{
    int marks = 7, subjects = 2;

    double wrong = marks / subjects;           // int division happens first: 3
    double right = (double)marks / subjects;   // cast first: 3.5
    printf("Without cast: %.1f\n", wrong);
    printf("With cast   : %.1f\n", right);

    // precedence: * before +
    printf("2 + 3 * 4   = %d\n", 2 + 3 * 4);     // 14
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);   // 20
    return 0;
}
