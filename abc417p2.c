#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int A[100], B[100];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < M; i++)
    {
        int b = B[i];
        for (int j = 0; j < N; j++)
        {
            if (A[j] == b)
            {
                for (int k = j; k < N - 1; k++)
                {
                    A[k] = A[k + 1];
                }
                N--;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}