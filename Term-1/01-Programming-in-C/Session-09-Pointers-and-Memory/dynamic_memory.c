#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count;
    printf("How many ports? ");
    if (scanf("%d", &count) != 1 || count <= 0 || count > 1000) return 1;

    int *ports = malloc(count * sizeof(int));   // ask for memory
    if (ports == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
        ports[i] = 8000 + i;                    // fill it

    for (int i = 0; i < count; i++)
        printf("%d ", ports[i]);
    printf("\n");

    free(ports);        // give memory back
    ports = NULL;       // avoid use-after-free
    return 0;
}
