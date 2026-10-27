#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 5; row++) {          // outer loop
        for (int col = 1; col <= 5; col++) {      // inner loop
            printf("%4d", row * col);
        }
        printf("\n");                             // new line after each row
    }
    return 0;
}
