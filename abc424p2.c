#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    bool solved[N + 1][M + 1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            solved[i][j] = false;
        }
    }
    int solvedCount[N + 1];
    for (int i = 1; i <= N; i++)
        solvedCount[i] = 0;
    int finishTime[N + 1];
    for (int i = 1; i <= N; i++)
        finishTime[i] = -1;
    for (int t = 1; t <= K; t++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        if (!solved[A][B])
        {
            solved[A][B] = true;
            solvedCount[A]++;
            if (solvedCount[A] == M)
            {
                finishTime[A] = t;
            }
        }
    }
    for (int time = 1; time <= K; time++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (finishTime[i] == time)
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}