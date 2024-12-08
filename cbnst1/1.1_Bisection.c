#include <stdio.h>
#include <math.h>

float findValue(float x)
{
    return x * x * x - 2 * x - 5;
}

float bisect(float x1, float x2)
{
    return (x1 + x2) / 2;
}

int main()
{
    int maxIteration, i = 1;
    float x1, x2, x;

    printf("\nEnter the max number of iteration:");
    scanf("%d", &maxIteration);

    do
    {
        printf("\nEnter the values of X1 and X2:");
        scanf("%f%f", &x1, &x2);

        if (findValue(x1) * findValue(x2) > 0)
        {
            printf("\nRoots are invalid");
            continue;
        }
        else
        {
            printf("\nRoots lie between %f and %f ", x1, x2);
            break;
        }
    } while (1);

    while (i <= maxIteration)
    {
        x = bisect(x1, x2);

        if (findValue(x) * findValue(x1) < 0)
        {
            x2 = x;
        }
        else 
        {
            x1 = x;
        }
        printf("\nIterations=%d   Roots=%f", i, x);
        i++;
    }
    printf("\nRoot=%f  Total Iteration=%d", x, --i);
    return 0;
}