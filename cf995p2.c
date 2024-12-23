#include <stdio.h>

long long calculate_days(long long n, long long a, long long b, long long c)
{
    long long cycle_sum = a + b + c;
    long long cycles = n / cycle_sum;
    long long remaining = n % cycle_sum;
    long long total_days = cycles * 3;
    if (remaining > 0)
    {
        total_days++;
        remaining -= a;
        if (remaining > 0)
        {
            total_days++;
            remaining -= b;
            if (remaining > 0)
            {
                total_days++;
            }
        }
    }
    return total_days;
}

int main()
{
    int t;
    scanf("%d", &t);
    long long result[t];
    for (int i = 0; i < t; i++)
    {
        long long n, a, b, c;
        scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
        result[i] = calculate_days(n, a, b, c);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%lld\n", result[i]);
    }
    return 0;
}

// CodeForces Contest 995 P2
// Accepted YAY!