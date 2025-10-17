#include <stdio.h>
#include <math.h>

int isPerfectSquare(long long n)
{
    if (n < 0)
        return 0;
    long long sqrt_n = sqrt(n);
    return (sqrt_n * sqrt_n == n);
}
void findPair(long long N)
{
    if (N == 1)
    {
        printf("-1\n");
        return;
    }
    long long max_d = cbrt(N);
    for (long long d = 1; d <= max_d; d++)
    {
        if (N % d == 0)
        {
            long long M = N / d;
            long long a = 3;
            long long b = 3 * d;
            long long c = d * d - M;
            long long discriminant = b * b - 4 * a * c;
            if (discriminant >= 0 && isPerfectSquare(discriminant))
            {
                long long sqrt_discriminant = sqrt(discriminant);
                long long y = (-b + sqrt_discriminant) / (2 * a);
                if (y > 0 && (a * y * y + b * y + c) == 0)
                {
                    long long x = y + d;
                    printf("%lld %lld\n", x, y);
                    return;
                }
            }
        }
    }
    printf("-1\n");
}

int main()
{
    long long N;
    scanf("%lld", &N);
    findPair(N);
    return 0;
}