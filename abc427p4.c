#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    if (scanf("%d", &T) != 1)
        return 0;
    while (T--)
    {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        char *S = malloc((N + 3) * sizeof(char));
        scanf("%s", S + 1);
        int *edgesU = malloc(M * sizeof(int));
        int *edgesV = malloc(M * sizeof(int));
        int *outdeg = calloc(N + 2, sizeof(int));
        for (int i = 0; i < M; ++i)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edgesU[i] = u;
            edgesV[i] = v;
            outdeg[u]++;
        }
        int *start = malloc((N + 2) * sizeof(int));
        start[1] = 0;
        for (int i = 1; i <= N; ++i)
            start[i + 1] = start[i] + outdeg[i];
        int *to = malloc(M * sizeof(int));
        int *pos = malloc((N + 2) * sizeof(int));
        for (int i = 1; i <= N; ++i)
            pos[i] = start[i];
        for (int i = 0; i < M; ++i)
        {
            int u = edgesU[i], v = edgesV[i];
            to[pos[u]++] = v;
        }
        free(edgesU);
        free(edgesV);
        free(pos);
        free(outdeg);
        int *prev = malloc((N + 2) * sizeof(int));
        int *cur = malloc((N + 2) * sizeof(int));
        for (int u = 1; u <= N; ++u)
            prev[u] = (S[u] == 'A') ? 1 : 0;
        int total = 2 * K;
        for (int t = 1; t <= total; ++t)
        {
            if ((t % 2) == 0)
            {
                for (int u = 1; u <= N; ++u)
                {
                    int val = 0;
                    for (int idx = start[u]; idx < start[u + 1]; ++idx)
                    {
                        if (prev[to[idx]])
                        {
                            val = 1;
                            break;
                        }
                    }
                    cur[u] = val;
                }
            }
            else
            {
                for (int u = 1; u <= N; ++u)
                {
                    int val = 1;
                    for (int idx = start[u]; idx < start[u + 1]; ++idx)
                    {
                        if (!prev[to[idx]])
                        {
                            val = 0;
                            break;
                        }
                    }
                    cur[u] = val;
                }
            }
            int *tmp = prev;
            prev = cur;
            cur = tmp;
        }
        if (prev[1])
            printf("Alice\n");
        else
            printf("Bob\n");
        free(S);
        free(start);
        free(to);
        free(prev);
        free(cur);
    }
    return 0;
}