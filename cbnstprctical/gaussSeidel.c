#include <stdio.h> 
#include <math.h> 
 
float equation1(float y, float z) { 
    return (44 - y - 2*z) / 10; 
} 
float equation2(float x, float z) { 
    return (51 - 2*x - z) / 10; 
} 
float equation3(float x, float y) { 
    return (61 - x - 2*y) / 10; 
} 
 
int main() { 
    float x = 0, y = 0, z = 0;   
    float x_new, y_new, z_new; 
    float aerr; 
    int iter = 0; 
 
    printf("Enter the allowed error: "); 
    scanf("%f", &aerr); 
    while(1){ 
        x_new = equation1(y, z);      
        y_new = equation2(x_new, z);  
        z_new = equation3(x_new, y_new);  
 
        if (fabs(x - x_new) < aerr && fabs(y - y_new) < aerr && fabs(z - z_new) < aerr) { 
            break;   
        } 
        x = x_new; 
        y = y_new; 
        z = z_new; 
        iter++; 
        printf("Approximation %d: x = %.4f, y = %.4f, z = %.4f\n", iter, x, y, z); 
    } 
    printf("\nSolution: x = %.4f, y = %.4f, z = %.4f\n", x, y, z); 
    return 0; 
} 
