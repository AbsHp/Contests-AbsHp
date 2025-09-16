#include <stdio.h>
#include <math.h>

int main()
{
    float a, b;
    scanf("%f %f", &a, &b);
    float d;
    int n;
    d = a/b;
    n = round(d);
    printf("%d", n);
    return 0;
}