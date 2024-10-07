#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - x - 1;
}

void bisection(double a, double b, double tolerance)
{
    if (f(a) * f(b) >= 0)
    {
        printf("Wrong interval.\n");
        return;
    }

    double c = a;
    while ((b - a) >= tolerance)
    {

        c = (a + b) / 2;

        if (f(c) == 0.0)
        {
            break;
        }

        else if (f(c) * f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    printf("The root is : %lf\n", c);
}

int main()
{
   double a, b, tolerance;

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the tolerance level: ");
    scanf("%lf", &tolerance);

    bisection(a, b, tolerance);

    return 0;
}
