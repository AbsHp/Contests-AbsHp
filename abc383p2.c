#include <stdio.h>
#include <stdlib.h>

#define MAX_H 100
#define MAX_W 100

int manhdist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
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
    int floor_cells[MAX_H * MAX_W][2];
    int floor_count = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (cells[i][j] == '.')
            {
                floor_cells[floor_count][0] = i;
                floor_cells[floor_count][1] = j;
                floor_count++;
            }
        }
    }
    int maxhum = 0;
    for (int a = 0; a < floor_count; a++)
    {
        for (int b = a + 1; b < floor_count; b++)
        {
            int x1 = floor_cells[a][0], y1 = floor_cells[a][1];
            int x2 = floor_cells[b][0], y2 = floor_cells[b][1];
            int hum[MAX_H][MAX_W] = {0};
            int hum_count = 0;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (cells[i][j] == '.' && manhdist(i, j, x1, y1) <= D)
                    {
                        if (!hum[i][j])
                        {
                            hum[i][j] = 1;
                            hum_count++;
                        }
                    }
                }
            }
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (cells[i][j] == '.' && manhdist(i, j, x2, y2) <= D)
                    {
                        if (!hum[i][j])
                        {
                            hum[i][j] = 1;
                            hum_count++;
                        }
                    }
                }
            }
            if (hum_count > maxhum)
            {
                maxhum = hum_count;
            }
        }
    }
    printf("%d\n", maxhum);
    return 0;
}

// AtCoder Beginner Contest 383 P2