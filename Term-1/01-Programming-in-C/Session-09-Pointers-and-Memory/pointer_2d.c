#include <stdio.h>

int main(void)
{
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            // both expressions read the same element
            printf("m[%d][%d] = %d  pointer form = %d\n",
                   i, j, m[i][j], *(*(m + i) + j));
        }
    }
    return 0;
}
