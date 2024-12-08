#include <stdio.h>
#include <math.h>
#include <string.h>

#define max 20

int main() {
    int i, j, k,n;
    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    float a[max][max + 1], c, x[max];
    memset(x, 0, max * sizeof(int));

    // Input validation for matrix size
    if (n > max) {
        printf("Matrix order exceeds the maximum allowed size.\n");
        return 1;
    }

    // Input the augmented matrix (coefficients + constants)
    printf("\nEnter the elements of the augmented matrix row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    // Convert to upper triangular matrix using Gaussian elimination
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i][i] != 0) {
                c = a[j][i] / a[i][i];  // Calculate factor
                for (k = 0; k < n + 1; k++) {
                    a[j][k] -= c * a[i][k];  // Subtract the appropriate multiple of the row
                }
            }
        }
    }

    // Backward substitution to find the solution vector x
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];  // Start from the last row
    for (i = n - 2; i >= 0; i--) {
        float sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];  // Sum the known terms in the equation
        }
        x[i] = (a[i][n] - sum) / a[i][i];  // Solve for x[i]
    }

    // Output the solution vector
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    return 0;
}
