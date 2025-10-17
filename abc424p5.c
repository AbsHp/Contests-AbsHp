#include <stdio.h>
#include <stdlib.h>

#define ll long long

int can(ll *A, int N, ll K, ll X, ll mid)
{
    ll count = 0;
    for (int i = 0; i < N; i++)
    {
        count += A[i] / mid;
        if (count >= X)
            return 1;
    }
    return count >= X;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        ll K, X;
        scanf("%d %lld %lld", &N, &K, &X);
        ll *A = (ll *)malloc(N * sizeof(ll));
        ll maxA = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%lld", &A[i]);
            if (A[i] > maxA)
                maxA = A[i];
        }
        ll low = 1, high = maxA, ans = 1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (can(A, N, K, X, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        printf("%lld\n", ans);
        free(A);
    }
    return 0;
}

// TLE :(