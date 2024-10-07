#include <stdio.h>

int main() {
    float real_value, approx_value;
    float absolute_error, relative_error, percentage_error;  

    printf("Enter the real (true) value: ");
    scanf("%f", &real_value);

    printf("Enter the approximate value: ");
    scanf("%f", &approx_value);

    absolute_error = (real_value > approx_value) ? (real_value - approx_value) : (approx_value - real_value);
    relative_error = absolute_error / real_value;
    percentage_error = relative_error * 100;

    printf("Absolute Error: %.4f\n", absolute_error);
    printf("Relative Error: %.4f\n", relative_error);
    printf("Percentage Error: %.2f%%\n", percentage_error);

    return 0;
}
