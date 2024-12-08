#include <stdio.h>
double f(double x, double y)
{
    return -2 * x * y;
}
void euler(double x0, double y0, double xEnd, double stepSize)
{
    double x = x0;
    double y = y0;
    printf("x\t\ty\n");
    printf("%.5lf\t\t%.5lf\n", x, y);
    while (x < xEnd)
    {
        y = y + stepSize * f(x, y);
        x = x + stepSize;
        printf("%.5lf\t\t%.5lf\n", x, y);
    }
}
int main()
{
    double x0, y0, xEnd, stepSize;
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter the end value of x: ");
    scanf("%lf", &xEnd);
    printf("Enter the step size: ");
    scanf("%lf", &stepSize);
    euler(x0, y0, xEnd, stepSize);
    return 0;
}