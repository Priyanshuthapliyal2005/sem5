#include <stdio.h>
#include <math.h>

float findValue(float x)
{
    return x * x * x - 5 * x + 1;
}

float findX(float x1, float x2)
{
    return (x1 * findValue(x2) - x2 * findValue(x1)) / (findValue(x2) - findValue(x1));
}

int main()
{
    int maxIeration, i = 1;
    float x1, x2, x, aerr;

    printf("\nEnter the max number of iterations:");
    scanf("%d", &maxIeration);

    printf("\nEnter the roots of the quation:");
    scanf("%f %f", &x1, &x2);

    printf("\nEnter the allowed error:");
    scanf("%f", &aerr);

    x = findX(x1, x2);

    do
    {
        x1 = x2;
        x2 = x;
        printf("\nIterations %d      Roots=%f", i, x);
        x = findX(x1, x2);

        if (fabs(x - x2) < aerr)
        {
            printf("\nIterations  %d     Root  %f", i + 1, x);
            return 0;
        }
        else
        {
            i++;
        }
    } while (i <= maxIeration);

    printf("\nIterations   %d    Roots   %f", i, x);
    return 0;
}