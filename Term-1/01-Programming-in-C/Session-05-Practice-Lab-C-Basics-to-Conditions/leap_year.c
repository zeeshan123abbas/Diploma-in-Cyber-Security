#include <stdio.h>

int main(void)
{
    int year;
    printf("Year: ");
    if (scanf("%d", &year) != 1) { printf("Invalid\n"); return 1; }

    // divisible by 4 and not by 100, OR divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
    return 0;
}
