#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 1 / (1 + x * x);  // Function to integrate
}

float onebythree(float a, float b, int n)
{
    float h, sum = 0;
    h = (b - a) / n;
    sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += 2 * f(a + i * h);
        }
        else
        {
            sum += 4 * f(a + i * h);
        }
    }

    sum *= h / 3;
    return sum;
}

float threebyeight(float a, float b, int n)
{
    float h, sum = 0;
    h = (b - a) / n;
    sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            sum += 2 * f(a + i * h);
        }
        else
        {
            sum += 3 * f(a + i * h);
        }
    }

    sum *= (3 * h) / 8;
    return sum;
}

int main()
{
    float a, b;
    int n;

    printf("Enter the lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%f", &b);

    printf("Enter the number of sub intervals: ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        float ans = onebythree(a, b, n);
        printf("The value of integration using 1/3 rule is: %f\n", ans);
    }
    else if (n % 3 == 0)
    {
        float ans = threebyeight(a, b, n);
        printf("The value of integration using 3/8 rule is: %f\n", ans);
    }
    else if ((n - 3) % 2 == 0)
    {
        // Use 3 subintervals for 3/8 Rule
        float ans3 = threebyeight(a, a + 3 * ((b - a) / n), 3);

        // Use the remaining subintervals for 1/3 Rule
        float ans1 = onebythree(a + 3 * ((b - a) / n), b, n - 3);

        float total_ans = ans3 + ans1;
        printf("The value of integration is: %f\n", total_ans);
    }
    else
    {
        printf("It is not possible to compute the integration with the given number of subintervals.\n");
    }

    return 0;
}
