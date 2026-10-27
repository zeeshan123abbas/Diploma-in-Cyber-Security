/* This file has deliberate mistakes. Compile with:
   gcc -Wall -Wextra buggy.c -o buggy
   and fix every error and warning. (It does not compile as it is.) */
#include <stdio.h>

int main(void)
{
    int marks
    printf("Marks: ");
    scanf("%d", marks);

    if (marks = 100)
        printf("Full marks!\n");
    else if (marks >= 50)
        printf("Pass\n")
    else
        printf("Fail\n");

    return 0;
}
