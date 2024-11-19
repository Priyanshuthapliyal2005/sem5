#include <stdio.h>
#include <math.h>

// Define the function f(x)
double f(double x) {
    return x*x+4*sin(x);  // Example function f(x) = 3x - cos(x) - 1
}

// Define the derivative f'(x)
double f_prime(double x) {
    return 2*x + 4*cos(x);  // Derivative of f(x)
}

int main() {
    double x0, x1, f0, f1, allowed_error;
    int iteration = 0, max_iterations = 1000;

    // Input initial guess and allowed error
    printf("Enter the initial guess: ");
    scanf("%lf", &x0);
    printf("Enter the allowed error: ");
    scanf("%lf", &allowed_error);

    // Newton-Raphson Iteration
    do {
        f0 = f(x0);       // Evaluate f(x0)
        f1 = f_prime(x0); // Evaluate f'(x0)

        if (fabs(f1) < 1e-10) {
            printf("Mathematical Error: The derivative is too close to zero.\n");
            return -1;
        }

        // Newton-Raphson formula to find new x1
        x1 = x0 - f0 / f1;

        // Display each iteration's result
        printf("Iteration %d: x1 = %.10lf\n", iteration + 1, x1);

        // Update x0 for the next iteration
        x0 = x1;
        iteration++;

        // If maximum iterations reached
        if (iteration >= max_iterations) {
            printf("Maximum iterations reached. Solution may not be accurate.\n");
            return -1;
        }

    } while (fabs(f(x1)) > allowed_error);  // Check if result is within allowed error

    // Display the result
    printf("The root is approximately: %.10lf\n", x1);
    printf("Number of iterations: %d\n", iteration);

    return 0;
}
