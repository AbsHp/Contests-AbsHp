#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN (1 << 18)

bool visited[MAXN];
bool dangerous[MAXN];

void solve(int N, char *S)
{
    int total = (1 << N) - 1;
    for (int i = 1; i <= total; ++i)
    {
        visited[i] = false;
        dangerous[i] = (S[i - 1] == '1');
    }
    visited[0] = true;
    for (int mask = 0; mask < (1 << N); ++mask)
    {
        if (!visited[mask])
            continue;
        for (int j = 0; j < N; ++j)
        {
            if (!(mask & (1 << j)))
            {
                int new_mask = mask | (1 << j);
                if (new_mask == 0)
                    continue;
                if (dangerous[new_mask])
                    continue;
                if (!visited[new_mask])
                {
                    visited[new_mask] = true;
                }
            }
        }
    }
    if (visited[(1 << N) - 1])
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        int len = (1 << N) - 1;
        char *S = (char *)malloc((len + 1) * sizeof(char));
        scanf("%s", S);
        solve(N, S);
        free(S);
    }
    return 0;
}