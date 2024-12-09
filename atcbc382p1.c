#include <stdio.h>

int main()
{
    int N, D;
    scanf("%d %d\n", &N, &D);
    int c1 = 0; 
    int c2 = 0;
    char S[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &S[i]);
        if (S[i] == '@')
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    int result = c2 + D;
    printf("%d", result);
    return 0;
}

// AtCoder Beginner Contest 382 Problem 1