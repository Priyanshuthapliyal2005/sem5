#include <stdio.h>

int main() {
    float abs_err[3], real_val, min_err = 100;
    float approx_vals[3] = {0.30, 0.33, 0.34};
    int min_index = -1;

    printf("Enter the real (true) value:\n");
    scanf("%f", &real_val);

    for(int i = 0; i < 3; i++) {
        abs_err[i] = (real_val > approx_vals[i]) ? (real_val - approx_vals[i]) : (approx_vals[i] - real_val);
        printf("Absolute error for %.2f = %.5f\n", approx_vals[i], abs_err[i]);

        if(abs_err[i] < min_err) {
            min_err = abs_err[i];
            min_index = i;
        }
    }

    if(min_index != -1) {
        printf("\nThe best approximation = %.2f\n", approx_vals[min_index]);
    }

    return 0;
}
