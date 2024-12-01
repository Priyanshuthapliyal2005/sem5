#include <stdio.h>
double f(double x, double y) {
    return x + y;
}
void eulerMethod(double x0, double y0, double xn, double h) {
    double x = x0, y = y0;
    int iteration = 1;
    printf("Iteration\t x\t\t y\n");
    printf("------------------------------------------------\n");
    while (x < xn) {
        printf("%d\t\t %.4f\t %.4f\n", iteration, x, y);
        y = y + h * f(x, y); 
        x = x + h;          
        iteration++;
    }
    printf("%d\t\t %.4f\t %.4f\n", iteration, x, y);
}

int main() {
    double x0, y0, xn, h;
    
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter the value of x at which solution is required (xn): ");
    scanf("%lf", &xn);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    eulerMethod(x0, y0, xn, h);
  return 0;
}
