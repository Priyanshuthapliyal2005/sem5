#include <stdio.h>
#include <stdlib.h>

double f(double x)
{
    return x * x * x - 4 * x - 9;
}

double bisection(double a, double b, double err)
{
    if (f(a) * f(b) >= 0)
    {
        printf("Bisection fails.");
        return -1;
    }

    double midPt;
    int i = 0;

    while ((b - a) / 2.0 > err)
    {
        midPt = (a + b) / 2.0;
        i++;

        printf("iteration %d : root approximation = %lf , f(root)= %lf \n ", i, midPt, f(midPt));
        if (f(midPt) == 0.0)
        {
            return midPt;
        }
        else if (f(midPt) * f(a) < 0)
        {
            b = midPt;
        }
        else
        {
            a = midPt;
        }
    }
    return a+b /2.0;
}

int main()
{
    double a, b, error;
    printf("Enter the value of a and b: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the error: ");
    scanf("%lf", &error);

    double root = bisection(a, b, error);
    if (root != -1)
    {
        printf("Root is: %lf\n", root);
    }
    else
    {
        printf("Root not found in the given interval\n");
    }
    return 0;
}