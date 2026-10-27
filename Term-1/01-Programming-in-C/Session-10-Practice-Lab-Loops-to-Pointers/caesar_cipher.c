#include <stdio.h>
#include <string.h>
#include <ctype.h>

// shift letters forward by key places, keep other characters
void encrypt(char *text, int key)
{
    for (char *p = text; *p != '\0'; p++) {
        if (isupper((unsigned char)*p))
            *p = (char)('A' + (*p - 'A' + key) % 26);
        else if (islower((unsigned char)*p))
            *p = (char)('a' + (*p - 'a' + key) % 26);
    }
}

int main(void)
{
    char message[100];
    int key = 3;

    printf("Message: ");
    if (fgets(message, sizeof message, stdin) == NULL) return 1;
    message[strcspn(message, "\n")] = '\0';

    encrypt(message, key);
    printf("Encrypted: %s\n", message);

    encrypt(message, 26 - key);          // shifting back decrypts
    printf("Decrypted: %s\n", message);
    return 0;
}
