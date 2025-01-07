#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 1000
#define MAX_W 1000
#define INF 1000000000

int dh[] = {1, -1, 0, 0};
int dw[] = {0, 0, 1, -1};

typedef struct
{
    int x, y, moves, is_vertical;
} State;

char grid[MAX_H][MAX_W];
int dist[MAX_H][MAX_W][2];
int bfs(int startX, int startY, int goalX, int goalY)
{
    State queue[MAX_H * MAX_W * 2];
    int front = 0, back = 0;
    memset(dist, -1, sizeof(dist));
    dist[startX][startY][0] = 0;   
    dist[startX][startY][1] = 0;
    queue[back++] = (State){startX, startY, 0, 0};
    queue[back++] = (State){startX, startY, 0, 1};
    while (front < back)
    {
        State current = queue[front++];
        if (current.x == goalX && current.y == goalY)
        {
            return current.moves;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = current.x + dh[i];
            int ny = current.y + dw[i];
            int next_is_vertical = (i == 0 || i == 1);
            if (nx >= 0 && nx < MAX_H && ny >= 0 && ny < MAX_W && grid[nx][ny] != '#')
            {
                if (dist[nx][ny][next_is_vertical] == -1)
                {
                    dist[nx][ny][next_is_vertical] = current.moves + 1;
                    queue[back++] = (State){nx, ny, current.moves + 1, next_is_vertical};
                }
            }
        }
    }
    return -1;
}

int main()
{
    int H, W;
    scanf("%d %d", &H, &W);
    int startX, startY, goalX, goalY;
    for (int i = 0; i < H; i++)
    {
        scanf("%s", grid[i]);
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 'G')
            {
                goalX = i;
                goalY = j;
            }
        }
    }
    int result = bfs(startX, startY, goalX, goalY);
    if (result == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", result);
    }
    return 0;
}

// WA