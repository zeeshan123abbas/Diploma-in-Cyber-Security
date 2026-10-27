#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *logs[] = {
        "INFO user login", "WARN disk 85%", "ERROR db timeout",
        "INFO user logout", "ERROR failed login", "INFO backup done"
    };
    int count = sizeof(logs) / sizeof(logs[0]);
    int info = 0, warn = 0, error = 0;

    for (int i = 0; i < count; i++) {
        if (strncmp(logs[i], "INFO", 4) == 0)       info++;
        else if (strncmp(logs[i], "WARN", 4) == 0)  warn++;
        else if (strncmp(logs[i], "ERROR", 5) == 0) error++;
    }

    printf("INFO: %d  WARN: %d  ERROR: %d\n", info, warn, error);
    return 0;
}
