#include <stdio.h>

int isValidPort(int port);          // prototype

int main(void)
{
    int ports[] = {80, 70000, 443, -1};
    for (int i = 0; i < 4; i++) {
        printf("%d -> %s\n", ports[i],
               isValidPort(ports[i]) ? "valid" : "invalid");
    }
    return 0;
}

int isValidPort(int port)           // definition
{
    return port >= 0 && port <= 65535;   // 1 or 0
}
