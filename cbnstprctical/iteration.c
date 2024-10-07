#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

double f(double x)
{
    return pow(x, 3) - x - 1; // f(x) = x^3 - x - 1
}

double phi(double x)
{
    return cbrt(x + 1);
}

double phi_prime(double x)
{
    return 1.0 / (3.0 * pow(x + 1, 2.0 / 3.0)); // d(g(x))
}

int main()
{
    double x0, x1, epsilon;
    int maxi, i = 0;

    printf("Enter initial guess (x0): ");
    scanf("%lf", &x0);
    printf("Enter allowed error (epsilon): ");
    scanf("%lf", &epsilon);
    printf("Enter maximum iterations: ");
    scanf("%d", &maxi);

    if (fabs(phi_prime(x0)) >= 1)
    {
        printf("Convergence is not guaranteed.\n");
        return -1;
    }

    do
    {
        x1 = phi(x0);
        i++;

        if (fabs(f(x1)) <= epsilon || i >= maxi)
        {
            break;
        }

        x0 = x1;

    } while (1);

    if (fabs(f(x1)) <= epsilon)
    {
        printf("The root is: %lf after %d iterations.\n", x1, i);
    }
    else
    {
        printf("The root could not be found within the given iterations and accuracy.\n");
    }
    return 0;
}