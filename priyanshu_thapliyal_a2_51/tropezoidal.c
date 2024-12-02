#include <stdio.h>
#include <stdlib.h>

float eq(float x){
    return 1 / (1 + x * x);
}

int main(){
    int n, i;
    float upper, lower, h, sum = 0.0, x;

    printf("Enter the number of intervals: ");
    scanf("%d", &n);
    if (n <= 0){
        printf("Number of intervals must be greater than zero.\n");
        return -1;
    }
    printf("Enter the upper limit: ");
    scanf("%f", &upper);
    printf("Enter the lower limit: ");
    scanf("%f", &lower);

    h = (upper - lower) / n;

    sum += eq(lower) + eq(upper);
    for (i = 1; i < n; i++){
        x = lower + i * h;
        sum += 2 * eq(x);
    }
    sum *= (h / 2);
    printf("The approximate value using Trapezoidal Rule is: %f\n", sum);
    return 0;
}
