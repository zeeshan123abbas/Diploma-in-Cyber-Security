#include <stdio.h>

int main(void)
{
    int score;
    printf("Vulnerability score (0-10): ");
    scanf("%d", &score);

    if (score < 0 || score > 10) {      // reject bad input first
        printf("Invalid score\n");
    } else if (score >= 9) {
        printf("Critical\n");
    } else if (score >= 7) {
        printf("High\n");
    } else if (score >= 4) {
        printf("Medium\n");
    } else {
        printf("Low\n");
    }
    return 0;
}
