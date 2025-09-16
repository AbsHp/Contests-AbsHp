#include <stdio.h>
#include <math.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    unsigned long long current = 1;
    unsigned long long A;
    unsigned long long limit = 1;
    for (int i = 0; i < K; i++)
    {
        limit *= 10;
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%llu", &A);
        current *= A;
        if (current >= limit)
        {
            current = 1;
        }
    }
    printf("%llu\n", current);
    return 0;
}