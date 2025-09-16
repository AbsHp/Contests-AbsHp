#include <stdio.h>
#define MAX_N 10000
#define MAX_X 6000
#define min(a, b) ((a) < (b) ? (a) : (b))

int N, Q;
int P[MAX_N], A[MAX_N], B[MAX_N];
int final_mood[MAX_X];

int simulate(int mood)
{
    for (int i = 0; i < N; ++i)
    {
        if (P[i] >= mood)
        {
            mood += A[i];
        }
        else
        {
            mood -= B[i];
            if (mood < 0)
                mood = 0;
        }
    }
    return mood;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &P[i], &A[i], &B[i]);
    }
    for (int i = 0; i < MAX_X; ++i)
    {
        final_mood[i] = simulate(i);
    }
    scanf("%d", &Q);
    while (Q--)
    {
        int x;
        scanf("%d", &x);
        if (x < MAX_X)
        {
            printf("%d\n", final_mood[x]);
        }
        else
        {
            printf("%d\n", simulate(x));
        }
    }
    return 0;
}

// TLE :(