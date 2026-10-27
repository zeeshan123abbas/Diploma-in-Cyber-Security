#include <stdio.h>

int main(void)
{
    int marks[5] = {70, 85, 90, 60, 75};
    int size = sizeof(marks) / sizeof(marks[0]);
    int total = 0, highest = marks[0];

    for (int i = 0; i < size; i++) {
        total += marks[i];                 // add each element
        if (marks[i] > highest)
            highest = marks[i];            // remember the biggest
    }

    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", (double)total / size);
    printf("Highest : %d\n", highest);
    return 0;
}
