#include <stdio.h>
#include <math.h>
double f(double x)
{
    return x * x * x - x - 1;
}

double bisection(double a, double b, double allowedError)
{
    if (f(a) * f(b) >= 0)
    {
        printf("Bisection method fails .\n");
        return -1;
    }

    double midPoint;
    int i = 0;

    while ((b - a) / 2.0 > allowedError)
    {
        midPoint = (a + b) / 2.0;

        i++;

        printf("iteration %d : root approximation = %lf , f(root)= %lf \n ", i, midPoint, f(midPoint));

        if (f(midPoint) == 0.0)
        {
            return midPoint;
        }
        else if (f(a) * f(midPoint) < 0)
        {
            b = midPoint;
        }
        else
        {
            a = midPoint;
        }
    }

    return (a + b) / 2.0;
}

int main()
{
    double a, b, allowed_error;
    printf("Enter the lower bound of the range (a): ");
    scanf("%lf", &a);
    printf("Enter the upper bound of the range (b): ");
    scanf("%lf", &b);
    printf("Enter the allowed error: ");
    scanf("%lf", &allowed_error);
    double root = bisection(a, b, allowed_error);
    if (root != -1)
    {
        printf("The root is approximately: %lf\n", root);
    }
    return 0;
}