#include <stdio.h>
double f(double x, double y)
{
    return -2 * x * y;
}
void rungeKutta(double x0, double y0, double xEnd, double h)
{
    double x = x0;
    double y = y0;
    double k1, k2, k3, k4;
    printf("x\t\ty\n");
    printf("%.5lf\t%.5lf\n", x, y);
    while (x < xEnd)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
        printf("%.5lf\t%.5lf\n", x, y);
    }
}
int main()
{
    double x0, y0, xEnd, h;
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter the end value of x: ");
    scanf("%lf", &xEnd);
    printf("Enter the step size: ");
    scanf("%lf", &h);
    rungeKutta(x0, y0, xEnd, h);
    return 0;
}