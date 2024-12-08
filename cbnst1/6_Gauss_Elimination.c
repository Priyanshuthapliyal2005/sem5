#include <stdio.h>

int n;
void convertToUpperTriangular(float a[][n + 1], int n)
{
    int i, j, k, x, y;
    float ratio;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
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
void applyBackwardSubstitution(float a[][n + 1], float value[], int n)
{
    int i, j;
    float sum;
    value[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum = sum + a[i][j] * value[j];
        }
        value[i] = (a[i][n] - sum) / a[i][i];
    }
}

void printValues(float value[], int n)
{
    int i;
    printf("\nThe values of the unknowns are:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nValue[%d]=%f.", i, value[i]);
    }
}
int main()
{
    int i, j;

    printf("\nEnter the number of unknowns:");
    scanf("%d", &n);

    float a[n][n + 1], value[n];
    printf("\nEnter the augmented metrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    convertToUpperTriangular(a, n);
    applyBackwardSubstitution(a, value, n);
    printValues(value, n);
    return 0;
}