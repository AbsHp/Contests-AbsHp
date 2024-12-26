#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_H 1000
#define MAX_W 1000

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int startX, int startY, int H, int W, int D, char cells[MAX_H][MAX_W + 1], bool humidified[MAX_H][MAX_W])
{
    int queue[MAX_H * MAX_W][3];
    int front = 0, rear = 0;

    queue[rear][0] = startX;
    queue[rear][1] = startY;
    queue[rear][2] = 0;
    rear++;
    humidified[startX][startY] = true;

    while (front < rear)
    {
        int x = queue[front][0];
        int y = queue[front][1];
        int dist = queue[front][2];
        front++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && cells[nx][ny] != '#' && dist + 1 <= D)
            {
                if (!humidified[nx][ny])
                {
                    humidified[nx][ny] = true;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    queue[rear][2] = dist + 1;
                    rear++;
                }
            }
        }
    }
}

int main()
{
    int H, W, D;
    scanf("%d %d %d", &H, &W, &D);
    char cells[MAX_H][MAX_W + 1];
    for (int i = 0; i < H; i++)
    {
        scanf("%s", cells[i]);
    }
    bool humidified[MAX_H][MAX_W] = {false};
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (cells[i][j] == 'H')
            {
                bfs(i, j, H, W, D, cells, humidified);
            }
        }
    }
    int humCount = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (humidified[i][j] && cells[i][j] != '#')
            {
                humCount++;
            }
        }
    }
    printf("%d\n", humCount);
    return 0;
}

// AtCoder Beginner Contest 383 P3 Alt