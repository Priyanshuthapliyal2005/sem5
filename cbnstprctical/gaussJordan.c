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

    for(i=0 ; i< n ;i++){
        float diagonal = A[i][i];
        for(j=0 ; j<= n ; j++){
            A[i][j] /= diagonal;
        }


        for(k=0 ; k<n ; k++){
            if(k!=i){
                c= A[k][i];
                for(j=0 ; j<= n ; j++){
                    A[k][j] -= c* A[i][j];
                }
            }
        }
    }

     printf("\nThe solution is:\n"); 
    for (i = 0; i < n; i++) { 
        printf("x%d = %f\t", i + 1, A[i][n]); 
    } 
    printf("\n"); 
 
    return 0; 
}