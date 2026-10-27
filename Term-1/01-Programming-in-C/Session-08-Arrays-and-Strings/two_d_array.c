#include <stdio.h>

int main(void)
{
    // 3 rows x 4 seats: 1 = occupied, 0 = free
    int seats[3][4] = {
        {1, 0, 1, 1},
        {0, 0, 1, 0},
        {1, 1, 1, 0}
    };
    int freeSeats = 0;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ", seats[row][col]);
            if (seats[row][col] == 0)
                freeSeats++;
        }
        printf("\n");
    }
    printf("Free seats: %d\n", freeSeats);
    return 0;
}
