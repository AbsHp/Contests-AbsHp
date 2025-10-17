#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    ll *A = malloc(sizeof(ll) * N);
    ll *prefix = malloc(sizeof(ll) * (2 * N + 1));
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < 2 * N; i++)
    {
        prefix[i + 1] = prefix[i] + A[i % N];
    }
    int offset = 0;
    for (int q = 0; q < Q; q++)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int c;
            scanf("%d", &c);
            offset = (offset + c) % N;
        }
        else if (type == 2)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            int start = offset + l - 1;
            int end = offset + r - 1;
            ll sum = prefix[end + 1] - prefix[start];
            printf("%lld\n", sum);
        }
    }
    free(A);
    free(prefix);
    return 0;
}