#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 200005

int A[MAXN], B[MAXN];
bool learned[MAXN];
int *adj[MAXN];
int adj_size[MAXN];
int queue[MAXN];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        if (A[i] != 0)
        {
            adj[A[i]] = realloc(adj[A[i]], (adj_size[A[i]] + 1) * sizeof(int));
            adj[A[i]][adj_size[A[i]]++] = i;
        }
        if (B[i] != 0)
        {
            adj[B[i]] = realloc(adj[B[i]], (adj_size[B[i]] + 1) * sizeof(int));
            adj[B[i]][adj_size[B[i]]++] = i;
        }
    }
    int front = 0, back = 0;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] == 0 && B[i] == 0)
        {
            learned[i] = true;
            queue[back++] = i;
        }
    }
    while (front < back)
    {
        int cur = queue[front++];
        for (int j = 0; j < adj_size[cur]; j++)
        {
            int dep = adj[cur][j];
            if (!learned[dep] && (learned[A[dep]] || learned[B[dep]]))
            {
                learned[dep] = true;
                queue[back++] = dep;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (learned[i])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}