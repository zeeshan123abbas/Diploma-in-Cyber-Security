#include <stdio.h>

#define MAX_ATTEMPTS 3            // preprocessor constant

int main(void)
{
    const float PI = 3.14159f;    // typed constant, read-only
    float radius = 2.5f;

    // area of a circle = PI * r * r
    float area = PI * radius * radius;

    printf("Allowed login attempts: %d\n", MAX_ATTEMPTS);
    printf("Area of circle (r = %.1f): %.2f\n", radius, area);

    // PI = 3.0f;   // uncomment this line: the compiler will refuse
    return 0;
}
