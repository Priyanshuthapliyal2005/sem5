// Parabolic Curve Fitting
#include <stdio.h>
#include <math.h>
#define S 50

int main()
{
    int n, i;
    float x[S], y[S];
    float sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    float sumY = 0, sumXY = 0, sumX2Y = 0;
    float a, b, c;
    float determinant, D1, D2, D3;

    printf("How many data points?\n");
    scanf("%d", &n);

    printf("Enter the data points (x and y):\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }

    // Calculate summations
    for (i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }

    // Calculate determinants
    determinant = n * (sumX2 * sumX4 - sumX3 * sumX3) -
                  sumX * (sumX * sumX4 - sumX3 * sumX2) +
                  sumX2 * (sumX * sumX3 - sumX2 * sumX2);

    D1 = sumY * (sumX2 * sumX4 - sumX3 * sumX3) -
         sumX * (sumXY * sumX4 - sumX3 * sumX2Y) +
         sumX2 * (sumXY * sumX3 - sumX2 * sumX2Y);

    D2 = n * (sumXY * sumX4 - sumX3 * sumX2Y) -
         sumY * (sumX * sumX4 - sumX3 * sumX2) +
         sumX2 * (sumX * sumX2Y - sumXY * sumX2);

    D3 = n * (sumX2 * sumX2Y - sumXY * sumX3) -
         sumX * (sumX * sumX2Y - sumXY * sumX2) +
         sumY * (sumX * sumX3 - sumX2 * sumX2);

    // Calculate coefficients
    a = D1 / determinant;
    b = D2 / determinant;
    c = D3 / determinant;

    printf("The parabolic curve fitting equation is: y = %.2f + %.2fx + %.2fx^2\n", a, b, c);

    return 0;
}
