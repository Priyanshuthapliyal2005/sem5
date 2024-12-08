#include<stdio.h>
#include<math.h>

float f (float x, float y)
{
    return (x+y);
}

int main(){
    float x0, y0, xEnd, h;
    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);

    printf("Enter the end value of x: ");
    scanf("%f", &xEnd);

    printf("Enter the step size: ");
    scanf("%f", &h);

    while(x0< xEnd){
        y0 = y0 + h * f(x0, y0);
        x0 = x0 + h;
        printf("x = %.5f, y = %.5f\n", x0, y0);
    }
    

    return 0;
}