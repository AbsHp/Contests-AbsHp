#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXH 1000
#define MAXW 1000

typedef struct
{
    int i, j;
} Cell;

int H, W;
char grid[MAXH][MAXW + 1];
int black_adj[MAXH][MAXW];
int visited[MAXH][MAXW];

Cell queue[MAXH * MAXW];
int front = 0, rear = 0;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

int in_bounds(int i, int j)
{
    return i >= 0 && i < H && j >= 0 && j < W;
}

void enqueue(int i, int j)
{
    queue[rear++] = (Cell){i, j};
}

Cell dequeue()
{
    return queue[front++];
}

int main()
{
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++)
    {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == '.')
            {
                int count = 0;
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + di[d], nj = j + dj[d];
                    if (in_bounds(ni, nj) && grid[ni][nj] == '#')
                    {
                        count++;
                    }
                }
                black_adj[i][j] = count;
                if (count == 1)
                {
                    enqueue(i, j);
                    visited[i][j] = 1;
                }
            }
        }
    }
    while (front < rear)
    {
        Cell curr = dequeue();
        int i = curr.i, j = curr.j;
        grid[i][j] = '#';
        for (int d = 0; d < 4; d++)
        {
            int ni = i + di[d], nj = j + dj[d];
            if (in_bounds(ni, nj) && grid[ni][nj] == '.')
            {
                black_adj[ni][nj]++;
                if (!visited[ni][nj] && black_adj[ni][nj] == 1)
                {
                    enqueue(ni, nj);
                    visited[ni][nj] = 1;
                }
            }
        }
    }
    int black_count = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == '#')
            {
                black_count++;
            }
        }
    }
    printf("%d\n", black_count);
    return 0;
}

// RE and WA