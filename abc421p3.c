#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long min_swaps(const char *S, int N, int startWithA)
{
    int len = 2 * N;
    int *posA = (int *)malloc(N * sizeof(int));
    int countA = 0;
    for (int i = 0; i < len; i++)
    {
        if (S[i] == 'A')
        {
            posA[countA++] = i;
        }
    }
    long long swaps = 0;
    for (int i = 0; i < N; i++)
    {
        int expected = (startWithA ? 2 * i : 2 * i + 1);
        swaps += llabs(posA[i] - expected);
    }
    free(posA);
    return swaps;
}

int main()
{
    int N;
    scanf("%d", &N);
    char *S = (char *)malloc((2 * N + 1) * sizeof(char));
    scanf("%s", S);
    long long res1 = min_swaps(S, N, 1);
    long long res2 = min_swaps(S, N, 0);
    long long ans = (res1 < res2 ? res1 : res2);
    printf("%lld\n", ans);
    free(S);
    return 0;
}