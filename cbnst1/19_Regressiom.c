#include <math.h>
#include <stdio.h>
int main()
{
    int n, i;
    float x, y, m, c, d;
    float sumx = 0, sumxsq = 0, sumy = 0, sumxy = 0;
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the values of x and y for data point %d: ", i + 1);
        scanf("%f%f", &x, &y);
        sumx += x;
        sumxsq += x * x;
        sumy += y;
        sumxy += x * y;
    }
    d = n * sumxsq - sumx * sumx;
    m = (n * sumxy - sumx * sumy) / d;
    c = (sumy * sumxsq - sumx * sumxy) / d;
    printf("The regression line is: y = %.2fx + %.2f\n", m, c);
    return 0;
}