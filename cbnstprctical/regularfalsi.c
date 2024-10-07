#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x*x*x - 5*x + 1; // Example: f(x) = x^3 - 5x + 1
}

// Main function
int main() {
    double x0, x1, x_r, e;
    int max_iterations = 1000, iteration = 0;

    // Input initial guesses and tolerable error
    printf("Enter the first initial guess (x0): ");
    scanf("%lf", &x0);
    printf("Enter the second initial guess (x1): ");
    scanf("%lf", &x1);
    printf("Enter the allowed error (e): ");
    scanf("%lf", &e);

    // Check if f(x0) and f(x1) have opposite signs
    if (f(x0) * f(x1) >= 0) {
        printf("The function must have opposite signs at the endpoints.\n");
        return -1;
    }

    do {
        // Calculate the point
        x_r = x1 - (f(x1) * (x0 - x1)) / (f(x0) - f(x1));
        printf("Iteration %d: x_r = %.10lf, f(x_r) = %.10lf\n", iteration + 1, x_r, f(x_r));

        // Check for convergence
        if (fabs(f(x_r)) < e) {
            printf("The root is approximately: %.10lf\n", x_r);
            printf("Number of iterations: %d\n", iteration + 1);
            return 0;
        }

        // Update the interval
        if (f(x_r) * f(x0) < 0) {
            x1 = x_r; // Root is in [x0, x_r]
        } else {
            x0 = x_r; // Root is in [x_r, x1]
        }

        iteration++;
        // Check for maximum iterations
        if (iteration >= max_iterations) {
            printf("Maximum iterations reached. Solution may not be accurate.\n");
            return -1;
        }

    } while (1); // Continue until root is found or max iterations reached
}
