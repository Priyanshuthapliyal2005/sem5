#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return x + y * y; // Define the differential equation
}

int main()
{
    float xo, yo, h, xn;
    
    // Input values
    printf("Enter the initial values of x and y: ");
    scanf("%f %f", &xo, &yo);

    printf("Enter the step size (h): ");
    scanf("%f", &h);

    printf("Enter the value of x at which you want to find the value of y: ");
    scanf("%f", &xn);

    // Ensure xn > xo
    if (xn <= xo) {
        printf("Error: xn must be greater than xo.\n");
        return 1;
    }

    printf("\n x\t\t y\n");
    printf("%.5f\t%.5f\n", xo, yo); // Print initial values

    // Runge-Kutta 4th Order Method
    while (xo < xn)
    {
        float k1 = h * f(xo, yo);
        float k2 = h * f(xo + h / 2, yo + k1 / 2);
        float k3 = h * f(xo + h / 2, yo + k2 / 2);
        float k4 = h * f(xo + h, yo + k3);

        float k = (1.0 / 6) * (k1 + 2 * k2 + 2 * k3 + k4); // Correct floating-point division
        yo = yo + k;
        xo = xo + h;

        // Print intermediate values
        printf("%.5f\t%.5f\n", xo, yo);
    }

    return 0;
}
