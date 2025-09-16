#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long a, b;
} Exchange;

int cmp(const void *x, const void *y)
{
    Exchange *e1 = (Exchange *)x;
    Exchange *e2 = (Exchange *)y;
    __int128 left = (__int128)e1->b * e2->a;
    __int128 right = (__int128)e2->b * e1->a;
    if (left > right)
        return -1;
    else if (left < right)
        return 1;
    else
        return 0;
}

int main()
{
    long long N;
    int M;
    scanf("%lld %d", &N, &M);
    Exchange *exchanges = malloc(sizeof(Exchange) * M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%lld %lld", &exchanges[i].a, &exchanges[i].b);
    }
    qsort(exchanges, M, sizeof(Exchange), cmp);
    long long bottles = N;
    long long empties = 0;
    long long stickers = 0;
    while (1)
    {
        empties += bottles;
        bottles = 0;
        int used = 0;
        for (int i = 0; i < M; ++i)
        {
            long long a = exchanges[i].a;
            long long b = exchanges[i].b;
            if (empties >= a)
            {
                long long times = empties / a;
                empties -= times * a;
                bottles += times * b;
                stickers += times;
                used = 1;
                break;
            }
        }
        if (!used)
            break;
    }
    printf("%lld\n", stickers);
    free(exchanges);
    return 0;
}

// WA :(