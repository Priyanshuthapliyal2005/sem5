#include<stdio.h>
#include<stdlib.h>

int main(){
    float x, y , h, u ;
    int n ;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float a[n][n+1];

    printf("Enter the values of x:\n");
    for(int i=0 ; i < n ; i++){
        scanf("%f", &a[i][0]);
    }
    printf("Enter the values of y:\n");
    for(int i=0 ; i < n ; i++){
        scanf("%f", &a[i][1]);
    }


    // diff table 
    for(int j= 2 ; j<= n ; j++){
        for(int i =0 ; i < n-j+1 ; i++){
            a[i][j] = a[i+1][j-1] - a[i][j-1];
        }
    }

    //displaying the table
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n-i+1 ; j++){
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }


    //step size 
    h= a[1][0] - a[0][0];
    u =(x-a[0][0])/h;

    y = a[0][1];
    
    float u1 = u;
    float fact = 1;
    for(int i=2 ; i<=n ; i++){
        y +=(u1 * a[0][i]) /fact;
        fact *= i;
        u1 *= (u-(i-1));
    }
    printf("\nValue of y at x = %.5f is %.5f\n", x, y);
    return 0;

}