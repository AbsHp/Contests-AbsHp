#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 200005

int H, W;
long long **A;
long long *P;
long long INF = 1LL << 60;

long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }

bool isPossible(long long x)
{
    long long **dp = malloc(H * sizeof(long long *));
    for (int i = 0; i < H; i++)
    {
        dp[i] = malloc(W * sizeof(long long));
        for (int j = 0; j < W; j++)
            dp[i][j] = -INF;
    }
    dp[0][0] = x + A[0][0] - P[0];
    if (dp[0][0] < 0)
        return false;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int k = i + j;
            if (dp[i][j] < 0)
                continue;
            if (i + 1 < H)
            {
                long long coins = dp[i][j] + A[i + 1][j] - P[k + 1];
                if (coins >= 0)
                {
                    dp[i + 1][j] = max(dp[i + 1][j], coins);
                }
            }
            if (j + 1 < W)
            {
                long long coins = dp[i][j] + A[i][j + 1] - P[k + 1];
                if (coins >= 0)
                {
                    dp[i][j + 1] = max(dp[i][j + 1], coins);
                }
            }
        }
    }
    bool result = dp[H - 1][W - 1] >= 0;
    for (int i = 0; i < H; i++)
        free(dp[i]);
    free(dp);
    return result;
}

int main()
{
    scanf("%d %d", &H, &W);
    A = malloc(H * sizeof(long long *));
    for (int i = 0; i < H; i++)
    {
        A[i] = malloc(W * sizeof(long long));
        for (int j = 0; j < W; j++)
        {
            scanf("%lld", &A[i][j]);
        }
    }
    int days = H + W - 1;
    P = malloc(days * sizeof(long long));
    for (int i = 0; i < days; i++)
    {
        scanf("%lld", &P[i]);
    }
    long long low = 0, high = 1e15, ans = -1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (isPossible(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%lld\n", ans);
    for (int i = 0; i < H; i++)
        free(A[i]);
    free(A);
    free(P);
    return 0;
}