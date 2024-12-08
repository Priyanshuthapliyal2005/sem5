#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return 1 / (1 + x * x);
}

int main() {
    int n;
    printf("Enter the number of intervals (must be a multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Simpson's 3/8 rule cannot be applied. Number of intervals must be a multiple of 3.\n");
        return -1;
    }

    float a, b;
    printf("Enter the lower limit: ");
    scanf("%f", &a);

    printf("Enter the upper limit: ");
    scanf("%f", &b);

    float sum = 0;
    sum += f(a) + f(b);
    float h = (b - a) / n;

    for (int i = 1; i <= n - 1; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }

    sum *= 3 * h / 8;

    printf("The approximate value is: %f\n", sum);

    return 0;
}