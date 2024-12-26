#include <stdio.h>
#include <string.h>

int countclusters (const char* str, char targetchar, int size)
{
    int straw = 0;
    int currentclustersize = 0;
    if (str == NULL || str[0] == '\0')
    {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
    }
        
    return straw;
}

int main()
{
    int N, K;
    char targetchar = '0';
    int straw = 0;
    scanf("%d %d", &N, &K);
    char T[N+1];
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &T[i]);
    }
    return 0;
}

// AtCoder Beginner Contest 379 Problem 2