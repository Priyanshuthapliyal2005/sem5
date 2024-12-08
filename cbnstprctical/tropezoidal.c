#include<stdio.h>
#include<math.h>

float f(float x) {
    return 1 / (1 + sin(x));
}

int main() {
    float a, b, n;
    printf("Enter the number of intervals: ");
    scanf("%f", &n);

    printf("Enter the lower limit: ");
    scanf("%f", &a);

    printf("Enter the upper limit: ");  
    scanf("%f", &b);

    float sum = 0, h = 0;
    sum = f(a) + f(b);

    h = (b - a) / n;  // Calculate the step size

    // Loop from a+h to b-h (inclusive), adding the values at the inner points
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }

    sum *= h / 2;  // Apply the trapezoidal rule formula

    printf("The value of the integral is: %f\n", sum);

    return 0;
}
