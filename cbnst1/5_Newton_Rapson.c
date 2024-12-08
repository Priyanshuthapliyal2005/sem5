#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x * x - 3 * x - 5;
}

float differentiate(float x)
{
    return 3 * x * x - 3;
}
int main()
{
    int maxIteration, i;
    float x1, x2, x0, x, aerr;

    printf("\nEnter the max number of iteration.");
    scanf("%d", &maxIteration);

    do
    {
        printf("\nEnter the value of X1 and X2:");
        scanf("%f %f", &x1, &x2);

        if (f(x1) * f(x2) > 0)
        {
            printf("\nInvalid roots please enter different value.");
            continue;
        }
        else
        {
            printf("\nRoota lie between %f and %f .", x1, x2);
            break;
        }
    } while (1);

    printf("\nEnter the allowed error:");
    scanf("%f", &aerr);

    x0 = (x1 + x2) / 2;

    for (i = 1; i <= maxIteration; i++)
    {
        x = x0 - (f(x0) / differentiate(x0));
        if (fabs(x - x0) < aerr)
        {
            printf("\nFinal root is: %f    iterations: %d", x, i);
            return 0;
        }
        printf("\nIterations: %d    root:  %f", i, x);
        x0 = x;
    }

    printf("\nThe resultant root is %f with iterations %d", x, --i);

    return 0;
}