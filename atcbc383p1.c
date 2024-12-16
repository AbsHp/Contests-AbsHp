#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int T[N], V[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &T[i], &V[i]);
    }
    int prevtime = 0;
    int netamt = 0;
    for (int i = 0; i < N; i++)
    {
        netamt -= (T[i] - prevtime);
        if (netamt < 0)
        {
            netamt = 0;
        }
        netamt += V[i];
        prevtime = T[i];
    }
    printf("%d\n", netamt);
    return 0;
}

// AtCoder Beginner Contest 383 P1