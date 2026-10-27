#include <stdio.h>
#include <string.h>

int main(void)
{
    char username[16];

    printf("Username: ");
    if (fgets(username, sizeof username, stdin) == NULL) return 1;
    username[strcspn(username, "\n")] = '\0';   // remove the newline

    printf("Length: %zu\n", strlen(username));

    if (strcmp(username, "admin") == 0)
        printf("Warning: default admin account used!\n");

    char greeting[32];
    snprintf(greeting, sizeof greeting, "Hello, %s", username);  // never overflows
    printf("%s\n", greeting);
    return 0;
}
