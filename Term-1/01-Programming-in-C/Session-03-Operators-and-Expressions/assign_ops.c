#include <stdio.h>

int main(void)
{
    int score = 10;

    score += 5;                 // 15
    score *= 2;                 // 30
    score -= 4;                 // 26
    printf("score = %d\n", score);

    int a = 5;
    int b = a++;                // b gets 5, then a becomes 6
    int c = ++a;                // a becomes 7, then c gets 7
    printf("a=%d b=%d c=%d\n", a, b, c);
    return 0;
}
