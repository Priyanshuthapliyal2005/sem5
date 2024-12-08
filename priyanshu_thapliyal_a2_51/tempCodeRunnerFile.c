// #include <stdio.h>
// #include <stdlib.h>

// float eq(float x){
//     return 1 / (1 + x * x);
// }

// int main(){
//     int n, i;
//     float upper, lower, h, sum = 0.0, x;

//     printf("Enter the number of intervals: ");
//     scanf("%d", &n);
//     if (n <= 0){
//         printf("Number of intervals must be greater than zero.\n");
//         return -1;
//     }
//     printf("Enter the upper limit: ");
//     scanf("%f", &upper);
//     printf("Enter the lower limit: ");
//     scanf("%f", &lower);

//     h = (upper - lower) / n;

//     sum += eq(lower) + eq(upper);
//     for (i = 1; i < n; i++){
//         x = lower + i * h;
//         sum += 2 * eq(x);
//     }
//     sum *= (h / 2);
//     printf("The approximate value using Trapezoidal Rule is: %f\n", sum);
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

float f(float x){
    return x*x*x;
}

int main(){
    int n,i,a,b;
    scanf("%d",&n);
    scanf("%d %d",&a,&b);


    float x[n+1],y[n+1];

    for(int i=0 ;i <= n; i++){
        x[i] = a + i * (float)(b - a) / n;
    }
    for(int i=0; i <= n; i++){
        y[i] = f(x[i]);
    }

    float ans = y[0] + y[n];
    for(int i=1; i < n; i++){
        ans += 2*y[i];
    }

    ans = ans * (b-a) / (2*n);
    printf("%d\n",ans);
}