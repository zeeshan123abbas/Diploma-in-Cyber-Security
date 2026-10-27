#include <stdio.h>

int main(void)
{
    int choice;
    printf("1. Ping  2. Port check  3. Exit\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:  printf("Running ping...\n");       break;
        case 2:  printf("Checking ports...\n");     break;
        case 3:  printf("Goodbye\n");               break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
