#include <stdio.h>

int main(void)
{
    int bytes[5] = {192, 168, 1, 10, 0};
    int *start = bytes;             // first element
    int *end = bytes + 4;           // last element

    for (int *p = start; p <= end; p++) {    // pointer comparison
        printf("address %p holds %d\n", (void *)p, *p);
    }
    printf("Elements from start to end: %td\n", end - start + 1);
    return 0;
}
