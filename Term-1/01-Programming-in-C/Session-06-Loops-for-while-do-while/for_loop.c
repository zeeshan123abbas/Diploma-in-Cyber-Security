#include <stdio.h>

int main(void)
{
    int start = 20, end = 25;

    for (int port = start; port <= end; port++) {
        printf("Checking port %d\n", port);
    }

    // comma operator: count up and down together
    for (int up = 1, down = 5; up <= 5; up++, down--) {
        printf("up=%d down=%d\n", up, down);
    }
    return 0;
}
