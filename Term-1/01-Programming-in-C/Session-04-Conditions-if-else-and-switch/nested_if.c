#include <stdio.h>

int main(void)
{
    int userId, pin;
    const int SAVED_ID = 101, SAVED_PIN = 4321;   // demo values only

    printf("User ID: ");
    scanf("%d", &userId);

    if (userId == SAVED_ID) {           // first question
        printf("PIN: ");
        scanf("%d", &pin);
        if (pin == SAVED_PIN) {         // second question
            printf("Welcome!\n");
        } else {
            printf("Wrong PIN\n");
        }
    } else {
        printf("Unknown user\n");
    }
    return 0;
}
