#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXH 8
#define MAXW 8
#define INF 1000000

int H, W;
char grid[MAXH][MAXW];

int ok(int prev, int cur, int W)
{
    for (int j = 0; j < W - 1; j++)
    {
        if ((prev & (1 << j)) && (prev & (1 << (j + 1))) &&
            (cur & (1 << j)) && (cur & (1 << (j + 1))))
        {
            return 0;
        }
    }
    return 1;
}

int popcount(int x)
{
    int c = 0;
    while (x)
    {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &H, &W);
        for (int i = 0; i < H; i++)
            scanf("%s", grid[i]);
        int rowMask[H];
        for (int i = 0; i < H; i++)
        {
            int mask = 0;
            for (int j = 0; j < W; j++)
            {
                if (grid[i][j] == '#')
                    mask |= (1 << j);
            }
            rowMask[i] = mask;
        }
        int maxMask = 1 << W;
        int dp[MAXH][1 << 7];
        for (int i = 0; i < MAXH; i++)
            for (int j = 0; j < (1 << 7); j++)
                dp[i][j] = INF;
        for (int mask = 0; mask < maxMask; mask++)
        {
            int repaint = popcount(rowMask[0] & (~mask)); // repaint #→.
            dp[0][mask] = repaint;
        }
        for (int r = 1; r < H; r++)
        {
            for (int prev = 0; prev < maxMask; prev++)
            {
                if (dp[r - 1][prev] == INF)
                    continue;
                for (int cur = 0; cur < maxMask; cur++)
                {
                    if (!ok(prev, cur, W))
                        continue;
                    int repaint = popcount(rowMask[r] & (~cur));
                    if (dp[r][cur] > dp[r - 1][prev] + repaint)
                    {
                        dp[r][cur] = dp[r - 1][prev] + repaint;
                    }
                }
            }
        }
        int ans = INF;
        for (int mask = 0; mask < maxMask; mask++)
        {
            if (dp[H - 1][mask] < ans)
                ans = dp[H - 1][mask];
        }
        printf("%d\n", ans);
    }
    return 0;
}