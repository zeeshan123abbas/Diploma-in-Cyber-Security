#include <stdio.h>

int main(void)
{
    const int CORRECT_PIN = 2468;   // demo only
    int pin = 0, attempts = 0;

    while (attempts < 3) {
        printf("Enter PIN: ");
        if (scanf("%d", &pin) != 1) return 1;
        attempts++;

        if (pin == CORRECT_PIN) {
            printf("Access granted\n");
            break;                       // stop asking
        }
        printf("Wrong PIN (%d of 3)\n", attempts);
    }

    if (attempts == 3 && pin != CORRECT_PIN)
        printf("Locked out\n");
    return 0;
}
