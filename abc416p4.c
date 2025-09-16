#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int cmp_desc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

#define MAXN 300005

int A[MAXN], B[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        int M;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &B[i]);
        }
        qsort(A, N, sizeof(int), cmp_asc);
        qsort(B, N, sizeof(int), cmp_desc);
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            int total = (A[i] + B[i]) % M;
            sum += total;
        }
        printf("%lld\n", sum);
    }
    return 0;
}

// WA