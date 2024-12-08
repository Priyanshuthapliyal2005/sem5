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
    float x1, x2, x, x3, aerr;

    printf("\nEnter the max number of iteration:");
    scanf("%d", &maxIteration);
    printf("\nEnter the allowed error");
    scanf("%f", &aerr);

    do
    {
        printf("\nEnter the values of x1 and x2");
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

    x = bisect(x1, x2);

    do
    {
        if (findValue(x) * findValue(x1) <=0)
        {
            x2 = x;
        }
        else
        {
            x1 = x;
        }
        printf("\nIteration =%d    Roots=%f", i, x);

        x3 = bisect(x1, x2);
        if (fabs(x3 - x) < aerr)
        {
            printf("\nRoot=%f   TotalIeration=%d", x, i);
            return 0;
        }
        x = x3;//else case
        i++;
    } while (i <= maxIteration);

    return 0;
}