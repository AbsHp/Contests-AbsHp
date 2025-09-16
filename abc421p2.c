#include <stdio.h>

long long f(long long x)
{
    long long rev = 0;
    while (x > 0)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

int main()
{
    long long X, Y;
    scanf("%lld %lld", &X, &Y);
    long long a[11];
    a[1] = X;
    a[2] = Y;
    for (int i = 3; i <= 10; i++)
    {
        a[i] = f(a[i - 1] + a[i - 2]);
    }
    printf("%lld\n", a[10]);
    return 0;
}