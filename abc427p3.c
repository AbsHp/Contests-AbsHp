#include <stdio.h>

int main()
{
    int N, M;
    if (scanf("%d %d", &N, &M) != 2)
        return 0;
    int u[M], v[M];
    for (int i = 0; i < M; ++i)
    {
        scanf("%d %d", &u[i], &v[i]);
        u[i]--;
        v[i]--;
    }
    int best = M;
    int maxMask = 1 << N;
    for (int mask = 0; mask < maxMask; ++mask)
    {
        int deletions = 0;
        for (int i = 0; i < M; ++i)
        {
            int cu = (mask >> u[i]) & 1;
            int cv = (mask >> v[i]) & 1;
            if (cu == cv)
                deletions++;
            if (deletions >= best)
                break;
        }
        if (deletions < best)
            best = deletions;
        if (best == 0)
            break;
    }
    printf("%d\n", best);
    return 0;
}