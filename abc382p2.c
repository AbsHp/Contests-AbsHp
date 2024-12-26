#include <stdio.h>

int main()
{
    int N, D;
    scanf("%d %d\n", &N, &D);
    char S[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &S[i]);
    }
    int count = 0;
    for (int i = N-1; i >= 0; i--)
    {
        if (S[i] == '@')
        {
            S[i] = '.';
            count ++;
        }
        if (count == D)
        {
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%c", S[i]);
    }
    return 0;
}

// AtCoder Beginner Contest 382 Problem 2