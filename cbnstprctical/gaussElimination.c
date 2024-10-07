#include <stdio.h> 
#include <math.h> 
#define MAX 20  

int main() { 
    int i, j, k, n; 
    float A[MAX][MAX + 1], c, x[MAX];  
    
    printf("\nEnter the order of the matrix: "); 
    scanf("%d", &n); 
    
    if (n > MAX) { 
        printf("Matrix order exceeds the maximum allowed size.\n"); 
        return 1; 
    } 
 
    printf("\nEnter the elements of the augmented matrix row-wise:\n"); 
    for (i = 0; i < n; i++) { 
        for (j = 0; j <= n; j++) { 
            printf("A[%d][%d] : ", i + 1, j + 1); 
            scanf("%f", &A[i][j]); 
        } 
    } 
 
    for (i = 0; i < n; i++) { 
        for (k = i + 1; k < n; k++) { 
            c = A[k][i] / A[i][i]; 
            for (j = 0; j <= n; j++) { 
                A[k][j] = A[k][j] - c * A[i][j]; 
            } 
        } 
    } 

    for (i = n - 1; i >= 0; i--) { 
        x[i] = A[i][n]; 
        for (j = i + 1; j < n; j++) { 
            x[i] = x[i] - A[i][j] * x[j]; 
        } 
        x[i] = x[i] / A[i][i]; 
    } 
 
    printf("\nThe solution is:\n"); 
    for (i = 0; i < n; i++) { 
        printf("x%d = %f\t", i + 1, x[i]); 
    } 
    printf("\n"); 
 
    return 0; 
} 
