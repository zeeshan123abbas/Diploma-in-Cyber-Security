#include <stdio.h>
#include <string.h>

int main(void)
{
    char data[128];
    unsigned int sum = 0;

    printf("Text: ");
    if (fgets(data, sizeof data, stdin) == NULL) return 1;
    data[strcspn(data, "\n")] = '\0';      // remove newline

    for (size_t i = 0; i < strlen(data); i++) {
        sum += (unsigned char)data[i];     // add each byte value
    }

    printf("Checksum (mod 256): %u\n", sum % 256);
    return 0;
}
