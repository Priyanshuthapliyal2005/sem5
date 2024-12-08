#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x * x + x * x - 1;
}

float findValue(float x)
{
    return 1 / sqrt(1 + x);
}

float differentiate(float x)
{
    return 1 / 2.0 * (pow(1, pow((1 + x), 3 / 2.0)));
}
int main()
{
    int maxIteration, i;
    float x1, x2, x0, x, aerr;

    printf("\nEnter the max number of iteration:");
    scanf("%d", &maxIteration);

    printf("\nEnter the allowed error.");
    scanf("%f", &aerr);

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

    x0 = (x1 + x2) / 2;
    if (differentiate(x0) < 1)
    {
        printf("\nThe function value is  correct and iteration method can be applied.");
    }

    else
    {
        printf("\nThe function value is not correct and iteration method can't be applied");
        return 0;
    }

    for (i = 1; i <= maxIteration; i++)
    {
        x = findValue(x0);
        if (fabs(x - x0) < aerr)
        {
            printf("\nFinal Roots: %f    Iterations: %d", x, i);
            return 0;
        }
        else
        {
            printf("\nIterations: %d    root: %f", i, x);
            x0 = x;
        }
    }
    printf("\nRoot: %f    Iterations: %d", x, --i);

    return 0;
}