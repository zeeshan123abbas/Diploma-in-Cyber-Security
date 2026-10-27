#include <stdio.h>

int main(void)
{
    int units;
    double bill = 0;

    printf("Units consumed: ");
    if (scanf("%d", &units) != 1 || units < 0) {
        printf("Invalid units\n");
        return 1;
    }

    if (units <= 100) {
        bill = units * 10.0;                          // first slab
    } else if (units <= 200) {
        bill = 100 * 10.0 + (units - 100) * 15.0;     // second slab
    } else {
        bill = 100 * 10.0 + 100 * 15.0 + (units - 200) * 20.0;
    }

    printf("Bill for %d units: Rs %.2f\n", units, bill);
    return 0;
}
