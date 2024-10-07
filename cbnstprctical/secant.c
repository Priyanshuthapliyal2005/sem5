#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - 5 * x + 1;
}

int main()
{
    double x0, x1, x2, f0, f1, allowed_error;
    int i = 0, maxi = 1000;

    printf("Enter the first initial guess: ");
    scanf("%lf", &x0);
    printf("Enter the second initial guess: ");
    scanf("%lf", &x1);
    printf("Enter the allowed error: ");
    scanf("%lf", &allowed_error);

    do
    {
        f0 = f(x0);
        f1 = f(x1);

        if (fabs(f1 - f0) < 1e-10)
        {
            printf("Mathematical Error");
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        printf("Iteration %d : x2 = %.10lf \n",  i+1, x2);

        x0= x1;
        x1= x2;

        i++;


        if(i>=maxi){
            printf("Maximum iteration reached . Solution may not be accurate. \n");
            return -1 ;
        }
    } while(fabs(f(x2)) > allowed_error);

     // Display the result
    printf("The root is approximately: %.10lf\n", x2);
    printf("Number of iterations: %d\n", i);

}