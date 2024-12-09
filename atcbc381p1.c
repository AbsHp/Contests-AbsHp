#include <stdio.h>

int main()
{
    int N, n;
    int N1, N2, N3;
    scanf("%d", &N);
    char S[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", &S[i]);
    }
    for (int j = 0; j < ((N+1)/2 - 1); j++)
    {
        if (S[j] == 1)
        {
            N1 == 1;
        }
    }
    for (int k = ((N+1)/2 - 1);;)
    {
        if (S[k] == "/")
        {
            N2 == 1;
        }
    }
    for (int l = ((N+1)/2); l < N; l++)
    {
        if (S[l] == 2)
        {
            N3 == 1;
        }
    }
    if (N1 == 1 && N2 == 1 && N3 == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}

// AtCoder Beginner Contest 381 Problem 1