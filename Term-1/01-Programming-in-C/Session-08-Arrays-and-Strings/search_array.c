#include <stdio.h>

int main(void)
{
    int blocked[] = {13, 47, 99, 120, 201};
    int size = sizeof(blocked) / sizeof(blocked[0]);
    int target, found = 0;

    printf("Last octet to check: ");
    if (scanf("%d", &target) != 1) return 1;

    for (int i = 0; i < size; i++) {
        if (blocked[i] == target) {
            printf("Blocked (found at index %d)\n", i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Allowed\n");
    return 0;
}
