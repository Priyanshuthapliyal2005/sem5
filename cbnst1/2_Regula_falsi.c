#include <stdio.h>
#include <math.h>

float findValue(float x)
{
    return x * x * x - 2 * x - 5;
}

float findX(float x1, float x2)
{
    return (x1 * findValue(x2) - x2 * findValue(x1)) / findValue(x2) - findValue(x1);
}
int main()
{

    int maxIteration, i = 1;
    float x, x1, x2, x3, aerr;

    printf("\nEnter the max number of iterations");
    scanf("%d", &maxIteration);

    printf("\nEnter the allowed error");
    scanf("%f", &aerr);

    do
    {
        printf("\nEnter the value roots X1 and X2");
        scanf("%f %f", &x1, &x2);

        if (findValue(x1) * findValue(x2) > 0)
        {
            printf("\nRoots are invalid");
            continue;
        }
        else
        {
            printf("\nRoots lie between %f and %f", x1, x2);
            break;
        }
    } while (1);

    x = findX(x1, x2);
    do
    {
        if (findValue(x) * findValue(x1) < 0)
        {
            x2 = x;
        }
        else
        {
            x1 = x;
        }
        printf("\nIteration =%d    Roots=%f", i, x);

        x3 = findX(x1, x2);

        if (fabs(x3 - x) < aerr)
        {
            printf("\nRoot=%f    Iterations=%d", x3, i);
            return 0;
        }
        x = x3;
        i++;
    } while (i <= maxIteration);
    return 0;
}