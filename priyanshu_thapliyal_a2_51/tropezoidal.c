#include <stdio.h>
double f(double x)
{
    return 1 + 1/(x*x);
}
double trapezoidal(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

int main()
{
    double a, b;
    int n;

    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals: ");
    scanf("%d", &n);

    double result = trapezoidal(a, b, n);
    printf("The approximate value of the integral is: %.6f\n", result);

    return 0;
}