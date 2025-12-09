#include <stdio.h>

int main()
{
    int W, B;
    scanf("%d %d", &W, &B);
    int w_g = W * 1000;
    int n = w_g / B + 1;
    printf("%d\n", n);
    return 0;
}