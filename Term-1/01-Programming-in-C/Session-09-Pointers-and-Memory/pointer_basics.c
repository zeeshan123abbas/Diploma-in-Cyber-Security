#include <stdio.h>

int main(void)
{
    int age = 21;
    int *p = &age;                  // p stores the address of age

    printf("age        = %d\n", age);
    printf("&age       = %p\n", (void *)&age);
    printf("p          = %p\n", (void *)p);
    printf("*p         = %d\n", *p);   // value at that address

    *p = 30;                        // change age through the pointer
    printf("age is now = %d\n", age);
    return 0;
}
