#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXH 1000
#define MAXW 1000
#define INF 1000000000

typedef struct
{
    int r, c;
} Node;

int H, W;
char S[MAXH][MAXW + 1];
int dist[MAXH][MAXW];

Node queue[MAXH * MAXW];
int qhead = 0, qtail = 0;

Node warp[26][MAXH * MAXW];

int warp_cnt[26];
int warp_used[26];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main()
{
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++)
    {
        scanf("%s", S[i]);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] >= 'a' && S[i][j] <= 'z')
            {
                int k = S[i][j] - 'a';
                warp[k][warp_cnt[k]++] = (Node){i, j};
            }
        }
    }
    dist[0][0] = 0;
    queue[qtail++] = (Node){0, 0};
    while (qhead < qtail)
    {
        Node cur = queue[qhead++];
        int r = cur.r, c = cur.c;
        int d = dist[r][c];
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;
            if (S[nr][nc] == '#')
                continue;
            if (dist[nr][nc] > d + 1)
            {
                dist[nr][nc] = d + 1;
                queue[qtail++] = (Node){nr, nc};
            }
        }
        if (S[r][c] >= 'a' && S[r][c] <= 'z')
        {
            int k = S[r][c] - 'a';
            if (!warp_used[k])
            {
                warp_used[k] = 1;
                for (int i = 0; i < warp_cnt[k]; i++)
                {
                    int nr = warp[k][i].r;
                    int nc = warp[k][i].c;
                    if (dist[nr][nc] > d + 1)
                    {
                        dist[nr][nc] = d + 1;
                        queue[qtail++] = (Node){nr, nc};
                    }
                }
            }
        }
    }
    int ans = dist[H - 1][W - 1];
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}