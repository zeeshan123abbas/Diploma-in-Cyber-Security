// Build: gcc main.c utils.c -o portcheck
#include <stdio.h>
#include "utils.h"          // our own header: use quotes

int main(void)
{
    int port;
    printf("Port: ");
    if (scanf("%d", &port) != 1) return 1;

    if (isValidPort(port))
        printf("%d is a valid port number\n", port);
    else
        printf("%d is NOT a valid port number\n", port);
    return 0;
}
