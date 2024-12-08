#include <stdio.h>

int main()
{
    int n, i;
    double x[100], y[100];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    double a, b, inputX, resultY;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the x and y values
    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    // Calculate the sums
    for (i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate the slope (a) and intercept (b)
    a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / n;

    // Print the linear equation
    printf("\nThe linear equation that fits the given data is:\n");
    printf("y = %.5lf * x + %.5lf\n", a, b);

    // Input a value of x to calculate y
    printf("\nEnter a value of x to calculate y: ");
    scanf("%lf", &inputX);

    // Calculate the value of y for the given x
    resultY = a * inputX + b;

    // Print the result
    printf("The value of y for x = %.5lf is y = %.5lf\n", inputX, resultY);

    return 0;
}
