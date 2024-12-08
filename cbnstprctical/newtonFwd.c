#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float x, y;

    // Input the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Declare a 2D array for the difference table
    float a[n][n + 1]; // n rows, n+1 columns

    // Input values for x
    printf("Enter the values of x: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i][0]); // Store x values in the first column
    }

    // Input values for y
    printf("Enter the values of y: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i][1]); // Store y values in the second column
    }

    // Input the value of x for which we need to calculate y
    printf("Enter the value of x for which you want to calculate y: ");
    scanf("%f", &x);

    // Create the difference table
    for (int j = 2; j <= n; j++) { // Start from the third column
        for (int i = 0; i <= n - j; i++) {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    // Display the difference table
    printf("\nThe Difference Table is as follows:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i; j++) {
            printf("%10.5f ", a[i][j]);
        }
        printf("\n");
    }

    // Compute h (step size) and u
    float h = a[1][0] - a[0][0]; // x1 - x0
    float u = (x - a[0][0]) / h;

    // Initialize y with the first y value (y0)
    y = a[0][1];

    // Apply Newton's forward formula
    float u_product = u;
    float fact = 1;
    for (int j = 2; j <= n; j++) {
        y += (u_product * a[0][j]) / fact;
        fact *= j; // Update factorial
        u_product *= (u - (j - 1)); // Update u_product
    }

    // Display the result
    printf("\nValue of y at x = %.5f is %.5f\n", x, y);

    return 0;
}
