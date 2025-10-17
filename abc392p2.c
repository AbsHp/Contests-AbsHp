#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int A[M];
    int C = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &A[i]);
        for (int j = 0; j < N; j++)
        {
            if (A[i] == j)
            {
                C++;
                X[j] = A[i];
            }
        }
    }
    printf("%d\n", N - C);
    for (int i = 0; i < N - C; i++)
    {
        printf("%d ", X[i]);
    }
    return 0;
}