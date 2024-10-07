#include<stdio.h>
#include<math.h>

double f(double  x){
    return pow(x,3)  - x- 1;
}

double phi(double x ){
    return cbtr(x+1);
}

double phi_prime(double x){
    return 1.0 / ( 3.0 * pow(x+1 , 2.0 / 3.0));
}

int main(){
    double x ,c1 , epsilon;
    int max_iteration =0;

    printf("Enter initial guess : ");
    scanf("%lf ", & x);

    printf("Enter allowed error :");
    scanf("%lf", &c1);

    printd("Enter maximum iterations : ");
    scanf("%d", &max_iteration);


    if()

}