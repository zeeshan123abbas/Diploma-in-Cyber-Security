#include <stdio.h>

int sumArray(const int *arr, int size)   // const: we will not change it
{
    int total = 0;
    for (int i = 0; i < size; i++)
        total += *(arr + i);             // same as arr[i]
    return total;
}

int main(void)
{
    int scores[] = {4, 8, 15, 16, 23};
    printf("Sum = %d\n", sumArray(scores, 5));
    return 0;
}
