#include <stdio.h>
#include <math.h>
float findValueAt(float x)
{
    return 1 / (1 + pow(x, 2));
}
int main()
{
    int n;
    float i, a, b, sum = 0, h;
    printf("Enter Value of a and b:\n");
    scanf("%f%f", &a, &b);
    printf("Enter no. of Intervals:\n");
    scanf("%d", &n);
    h = (b - a) / n;
    sum = findValueAt(a) + findValueAt(b);
    for (i = a + h; i < b; i = i + h)
        sum = sum + 2 * findValueAt(i);
    sum = (h * sum) / 2;
    printf("\nValue of The integral  = %f", sum);
}