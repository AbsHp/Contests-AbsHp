#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 1000000000

typedef struct
{
    int row, col;
    char color;
} Cell;

bool canColorGrid(int N, int M, Cell cells[])
{
    int *row_max_black = (int *)calloc(N + 1, sizeof(int));
    int *row_min_white = (int *)calloc(N + 1, sizeof(int));
    int *col_max_black = (int *)calloc(N + 1, sizeof(int));
    int *col_min_white = (int *)calloc(N + 1, sizeof(int));
    for (int i = 1; i <= N; i++)
    {
        row_max_black[i] = -1;
        row_min_white[i] = INF;
        col_max_black[i] = -1;
        col_min_white[i] = INF;
    }
    for (int i = 0; i < M; i++)
    {
        int x = cells[i].row;
        int y = cells[i].col;
        char color = cells[i].color;
        if (color == 'B')
        {
            if (y > row_max_black[x])
                row_max_black[x] = y;
            if (x > col_max_black[y])
                col_max_black[y] = x;
        }
        else if (color == 'W')
        {
            if (y < row_min_white[x])
                row_min_white[x] = y;
            if (x < col_min_white[y])
                col_min_white[y] = x;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (row_max_black[i] >= row_min_white[i])
            return false;
        if (col_max_black[i] >= col_min_white[i])
            return false;
    }
    free(row_max_black);
    free(row_min_white);
    free(col_max_black);
    free(col_min_white);
    return true;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    Cell *cells = (Cell *)malloc(M * sizeof(Cell));
    for (int i = 0; i < M; i++)
    {
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        cells[i].row = x;
        cells[i].col = y;
        cells[i].color = c;
    }
    if (canColorGrid(N, M, cells))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    free(cells);
    return 0;
}

// WA on some cases