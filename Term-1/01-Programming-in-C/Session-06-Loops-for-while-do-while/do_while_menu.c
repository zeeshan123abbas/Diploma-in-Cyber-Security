#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int choice;
    do {
        printf("\n1) Odd numbers 1-10  2) Quit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Not a number. Exiting.\n");
            exit(1);                         // stop the program with error code
        }
        if (choice == 1) {
            for (int n = 1; n <= 10; n++) {
                if (n % 2 == 0) continue;    // skip even numbers
                printf("%d ", n);
            }
            printf("\n");
        }
    } while (choice != 2);

    printf("Bye\n");
    return 0;
}
