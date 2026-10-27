#include <stdio.h>

int main(void)
{
    int length, digits, symbols, upper;
    int score = 0;

    printf("Length, digits, symbols, uppercase letters: ");
    if (scanf("%d %d %d %d", &length, &digits, &symbols, &upper) != 4) {
        printf("Please enter four numbers.\n");
        return 1;
    }

    if (length >= 12)      score += 2;    // long passwords count most
    else if (length >= 8)  score += 1;
    if (digits > 0)  score++;
    if (symbols > 0) score++;
    if (upper > 0)   score++;

    switch (score) {
        case 5: case 4: printf("Strong (%d/5)\n", score); break;
        case 3:         printf("Medium (%d/5)\n", score); break;
        default:        printf("Weak (%d/5)\n", score);
    }
    return 0;
}
