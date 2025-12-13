#include <stdio.h>
#include <stdlib.h>

#define MAXM 200000
#define HSIZE 1048576

typedef struct
{
    long long r, c;
    int used;
} Entry;

Entry table[HSIZE];

unsigned long long hash(long long r, long long c)
{
    unsigned long long x = (unsigned long long)r * 1000000007ULL + c;
    return x & (HSIZE - 1);
}
int exists(long long r, long long c)
{
    unsigned long long h = hash(r, c);
    while (table[h].used)
    {
        if (table[h].r == r && table[h].c == c)
            return 1;
        h = (h + 1) & (HSIZE - 1);
    }
    return 0;
}
void insert(long long r, long long c)
{
    unsigned long long h = hash(r, c);
    while (table[h].used)
    {
        h = (h + 1) & (HSIZE - 1);
    }
    table[h].used = 1;
    table[h].r = r;
    table[h].c = c;
}

int main()
{
    long long N;
    int M;
    scanf("%lld %d", &N, &M);
    long long count = 0;
    for (int i = 0; i < M; i++)
    {
        long long r, c;
        scanf("%lld %lld", &r, &c);
        int overlap = 0;
        for (int dr = -1; dr <= 1 && !overlap; dr++)
        {
            for (int dc = -1; dc <= 1; dc++)
            {
                if (exists(r + dr, c + dc))
                {
                    overlap = 1;
                    break;
                }
            }
        }
        if (!overlap)
        {
            insert(r, c);
            count++;
        }
    }
    printf("%lld\n", count);
    return 0;
}