#include <stdio.h>

int main(void)
{
    int key;                         // getchar returns an int

    printf("Press a key and Enter: ");
    key = getchar();                 // read one character

    printf("You pressed: ");
    putchar(key);                    // print that character
    putchar('\n');
    return 0;
}
