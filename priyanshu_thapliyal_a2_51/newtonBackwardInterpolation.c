#include<stdio.h>

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n;
    float value, u, sum, h;

    printf("Enter the number of values in x and y\n");
    scanf("%d", &n);

    int x[n], y[n], diff[n][n];

    printf("Enter the elements for x\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter the elements for y (f(x))\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
        diff[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%d\t", diff[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &value);

    h = x[1] - x[0];
    u = (value - x[n - 1]) / h;  
    sum = y[n - 1];
    
    for (int i = 1; i < n; i++) {
        float u_term = 1;
        for (int j = 0; j < i; j++) {
            u_term *= (u + j);
        }
        sum += (u_term * diff[n - 1][i]) / fact(i);  
    }

    printf("\nInterpolated value at x = %.0f is %.5f\n", value, sum);

    return 0;
}
