#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += i + 1;
    }
    printf("%d", result);
    return 0;
}

// AtCoder Beginner Contest 43 P1