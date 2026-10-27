#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30

// read name and marks for each student
void readStudents(char (*names)[NAME_LEN], int *marks, int count)
{
    for (int i = 0; i < count; i++) {
        printf("Name of student %d: ", i + 1);
        if (scanf("%29s", names[i]) != 1) exit(1);   // at most 29 chars
        printf("Marks: ");
        if (scanf("%d", &marks[i]) != 1) exit(1);
    }
}

// print all students as a table
void printStudents(char (*names)[NAME_LEN], const int *marks, int count)
{
    printf("\n%-5s %-20s %s\n", "No", "Name", "Marks");
    for (int i = 0; i < count; i++)
        printf("%-5d %-20s %d\n", i + 1, names[i], marks[i]);
}

// return index of the highest marks
int findTopper(const int *marks, int count)
{
    int best = 0;
    for (int i = 1; i < count; i++)
        if (marks[i] > marks[best]) best = i;
    return best;
}

int main(void)
{
    int count;
    printf("How many students (1-50)? ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 50) return 1;

    char (*names)[NAME_LEN] = malloc(count * sizeof *names);  // count names
    int *marks = malloc(count * sizeof *marks);
    if (names == NULL || marks == NULL) { printf("Out of memory\n"); return 1; }

    readStudents(names, marks, count);
    printStudents(names, marks, count);

    int top = findTopper(marks, count);
    printf("\nTopper: %s with %d marks\n", names[top], marks[top]);

    free(names);    // always release memory
    free(marks);
    return 0;
}
