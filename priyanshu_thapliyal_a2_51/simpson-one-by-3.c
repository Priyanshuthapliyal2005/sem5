// #include <stdio.h>
// #include <stdlib.h>

// float eq(float x) {
//     return 1 / (1 + x * x);
// }
// int main() {
//     int n, i;
//     float upper, lower, h, sum = 0.0, x;
//     printf("Enter the number of intervals: ");
//     scanf("%d", &n);
//     if (n % 2 != 0) {
//         printf("Simpson's 1/3 rule cannot be applied. Number of intervals must be even.\n");
//         return -1;
//     }
//     printf("Enter the upper limit: ");
//     scanf("%f", &upper);
//     printf("Enter the lower limit: ");
//     scanf("%f", &lower);
//     h = (upper - lower) / n;
//     sum += eq(lower) + eq(upper); 
//     for (i = 1; i < n; i++) {
//         x = lower + i * h;
//         if (i % 2 == 0) {
//             sum += 2 * eq(x); 
//         } else {
//             sum += 4 * eq(x); 
//         }
//     }
//     sum *= h / 3;

//     printf("The approximate value is: %f\n", sum);

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float x)
{
    return 1/(1+x*x);
}


int main(){
    int n ;
    printf("Enter the number of intervals: ");
    scanf("%d",&n);

    float a,b;
    printf("Enter the lower limit: ");
    scanf("%f",&a);
    printf("Enter the upper limit: ");
    scanf("%f",&b);


    float h = (b-a)/n;

    float sum = f(a) + f(b);

    for(int i= 1 ;i<n;i++){
        if(i%2==0){
            sum+=2*f(a+i*h);
        }else{
            sum+=4*f(a+i*h);
        }
    }

    sum = sum*h/3;

    printf("The approximate value is: %f\n",sum);
}