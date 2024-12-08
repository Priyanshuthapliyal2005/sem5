#include <stdio.h>
#include <math.h>

int n;

void convertToDiagonal(float a[][n + 1], int n)
{
    int i, j, k, x, y;
    float ratio;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++)
                {
                    a[j][k] = a[j][k] - (ratio * a[i][k]);

                    // printing the matrix after changes for (intermediate row)..
                }
                printf("\nIntermediate Forms.\n");
                for (x = 0; x < n; x++)
                {
                    for (y = 0; y < n + 1; y++)
                    {
                        printf("%f ", a[x][y]);
                    }
                    printf("\n");
                }
            }
        }
    }
}

void printValue(float a[][n + 1], int n)
{
    int i;
    printf("\nThe solutions of the given equations are:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d unknown variable value is: %f", i + 1, a[i][n] / a[i][i]);
    }
}
int main()
{
    int i, j;
    printf("\nEnter the number of unknowns:");
    scanf("%d", &n);
    float a[n][n + 1];

    printf("\nEnter the augmented matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    convertToDiagonal(a, n);
    printValue(a, n);
    return 0;
}