#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float x, h, u, y;

    // Input the number of terms
    printf("Enter no. of terms: ");
    scanf("%d", &n);

    // Declare a 2D array for the difference table
    float a[n][n + 1];

    // Input values for X
    printf("Enter Values of X:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i][0]);
    }

    // Input values for Y
    printf("Enter Values of Y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i][1]);
    }

    // Input the value of x for which y needs to be calculated
    printf("Enter the value of x for which you want y: ");
    scanf("%f", &x);

    // Create the difference table
    for (int j = 2; j <= n; j++) {  // Start from the third column
        for (int i = 0; i <= n - j; i++) {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    // Display the difference table
    printf("\nDifference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i; j++) {
            printf("%10.5f ", a[i][j]);
        }
        printf("\n");
    }

    // Step size
    h = a[1][0] - a[0][0];

    // Calculate u for backward interpolation
    u = (x - a[n - 1][0]) / h;

    // Initialize y with the last y value
    y = a[n - 1][1];

    // Apply Newton's Backward Interpolation Formula
    float u_term = u;
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        y += (u_term * a[n - i][i]) / fact;
        fact *= i;  // Update factorial
        u_term *= (u + (i - 1));  // Update u term
    }

    // Print the result
    printf("\nValue at X = %.5f is Y = %.5f\n", x, y);

    return 0;
}
