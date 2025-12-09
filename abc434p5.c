#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef long long ll;

typedef struct
{
    ll a, b;
} Rabbit;

int cmp(const void *p, const void *q)
{
    Rabbit *x = (Rabbit *)p;
    Rabbit *y = (Rabbit *)q;
    if (x->a < y->a)
        return -1;
    if (x->a > y->a)
        return 1;
    return 0;
}

#define SIZE 400003
ll taken[SIZE];

int hash_put(ll x)
{
    ll h = (x % SIZE + SIZE) % SIZE;
    while (taken[h] != (ll)9e18 && taken[h] != x)
    {
        h++;
        if (h == SIZE)
            h = 0;
    }
    if (taken[h] == x)
        return 0;
    taken[h] = x;
    return 1;
}

int hash_has(ll x)
{
    ll h = (x % SIZE + SIZE) % SIZE;
    while (taken[h] != (ll)9e18)
    {
        if (taken[h] == x)
            return 1;
        h++;
        if (h == SIZE)
            h = 0;
    }
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    Rabbit *arr = malloc(sizeof(Rabbit) * N);
    for (int i = 0; i < SIZE; i++)
        taken[i] = 9e18;
    ll X, R;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &X, &R);
        arr[i].a = X - R;
        arr[i].b = X + R;
    }
    qsort(arr, N, sizeof(Rabbit), cmp);
    int distinct = 0;
    for (int i = 0; i < N; i++)
    {
        ll A = arr[i].a, B = arr[i].b;
        if (!hash_has(A))
        {
            hash_put(A);
            distinct++;
        }
        else if (!hash_has(B))
        {
            hash_put(B);
            distinct++;
        }
    }
    printf("%d\n", distinct);
    free(arr);
    return 0;
}

// WA TLE for some cases :(