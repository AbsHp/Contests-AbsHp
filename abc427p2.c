#include <stdio.h>

long long digit_sum(long long x)
{
    long long s = 0;
    if (x < 0)
        x = -x;
    while (x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    long long A[101];
    A[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        long long sum = 0;
        for (int j = 0; j <= i - 1; ++j)
        {
            sum += digit_sum(A[j]);
        }
        A[i] = sum;
    }
    printf("%lld\n", A[N]);
    return 0;
}