#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 100
#define MAX_W 100

int isValidMove(int x, int y, int H, int W, char grid[MAX_H][MAX_W])
{
    return x >= 0 && x < H && y >= 0 && y < W && grid[x][y] != '#';
}

int main()
{
    int H, W, X, Y;
    char grid[MAX_H][MAX_W];
    char T[10001];
    scanf("%d %d %d %d", &H, &W, &X, &Y);
    X--;
    Y--;
    for (int i = 0; i < H; i++)
    {
        scanf("%s\n", grid[i]);
    }
    scanf("%s", T);
    int visited[MAX_H][MAX_W] = {0};
    int distinctHouses = 0;
    if (grid[X][Y] == '@' && !visited[X][Y])
    {
        visited[X][Y] = 1;
        distinctHouses++;
    }
    int len = strlen(T);
    for (int i = 0; i < len; i++)
    {
        int newX = X, newY = Y;
        if (T[i] == 'U')
            newX--;
        else if (T[i] == 'D')
            newX++;
        else if (T[i] == 'L')
            newY--;
        else if (T[i] == 'R')
            newY++;
        if (isValidMove(newX, newY, H, W, grid))
        {
            X = newX;
            Y = newY;
            if (grid[X][Y] == '@' && !visited[X][Y])
            {
                visited[X][Y] = 1;
                distinctHouses++;
            }
        }
    }
    printf("%d %d %d", X + 1, Y + 1, distinctHouses);
    return 0;
}