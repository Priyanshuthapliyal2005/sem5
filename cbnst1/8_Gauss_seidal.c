// Gauss Seidal Method
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float aerr;
    printf("Enter order of Matrix: ");
    scanf("%d", &n);
    float a[n][n + 1], x[n];
    printf("Enter Augmented Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
        // scanf("%f",&b[i]);
    }
    printf("Enter the allowed error: ");
    scanf("%f", &aerr);

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f\t", a[i][j]);
        }
        // printf("| %f\n",b[i]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        x[i] = 0;
    for (int k = 0; k < 100; k++)
    {
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += a[i][j] * x[j];
                }
            }
            float temp = (a[i][n] - sum) / a[i][i];
            if (fabs(temp - x[i]) < aerr)
                break;
            x[i] = temp;
        }
    }
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %f\n", i + 1, x[i]);
    }
    return 0;
}
