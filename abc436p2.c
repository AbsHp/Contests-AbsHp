#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int grid[100][100] = {0};
    int r = 0;
    int c = N / 2;
    grid[r][c] = 1;
    for (int k = 2; k <= N * N; k++)
    {
        int nr = (r - 1 + N) % N;
        int nc = (c + 1) % N;
        if (grid[nr][nc] == 0)
        {
            r = nr;
            c = nc;
        }
        else
        {
            r = (r + 1) % N;
        }
        grid[r][c] = k;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", grid[i][j]);
            if (j < N - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}