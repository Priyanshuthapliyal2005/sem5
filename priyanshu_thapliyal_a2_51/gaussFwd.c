#include <stdio.h>
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
void forwardDifferenceTable(float y[], int n) {
    float diffTable[n][n];
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
    printf("\nNewton Forward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]", i);
        for (int j = 0; j < n - i; j++) {
            printf("\t%.4f", diffTable[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        y[i] = diffTable[0][i];
    }
}
float gaussForwardInterpolation(float x[], float y[], int n, float value) {
    float result = y[0];
    float u = (value - x[0]) / (x[1] - x[0]);
    float u_term = u;
    forwardDifferenceTable(y, n);
    for (int i = 1; i < n; i++) {
        result += (u_term * y[i]) / factorial(i);
        u_term = u_term * (u - i);
    }
    return result;
}
int main() {
    int n;
    float value;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }
    printf("Enter the value of x to find f(x): ");
    scanf("%f", &value);
    float result = gaussForwardInterpolation(x, y, n, value);
    printf("\nThe interpolated value at x = %f is %f\n", value, result);
    return 0;
}
