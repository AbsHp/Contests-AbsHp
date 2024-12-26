#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    long long *coords = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &coords[i]);
    }
    for (int i = 0; i <= N - 4; i++)
    {
        long long M = (coords[i] + coords[i + 3]) / 2;
        coords[i + 1] = 2 * M - coords[i + 1];
        coords[i + 2] = 2 * M - coords[i + 2];
    }
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += coords[i];
    }
    printf("%lld\n", sum);
    free(coords);
    return 0;
}

// AtCoder Regular Contest 189 P2