#include <stdio.h>

int main(void)
{
    int attempts;

    printf("Failed login attempts so far: ");
    scanf("%d", &attempts);

    if (attempts < 3) {
        printf("You may try again.\n");
    } else {
        printf("Account locked. Contact the admin.\n");
    }
    return 0;
}
