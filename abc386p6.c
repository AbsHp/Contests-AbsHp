#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int editDistance(char *S, char *T, int K)
{
    int lenS = strlen(S);
    int lenT = strlen(T);
    if (abs(lenS - lenT) > K)
        return 0;
    int *prev = (int *)malloc((lenT + 1) * sizeof(int));
    int *curr = (int *)malloc((lenT + 1) * sizeof(int));
    for (int j = 0; j <= lenT; j++)
    {
        prev[j] = j;
    }
    for (int i = 1; i <= lenS; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= lenT; j++)
        {
            if (S[i - 1] == T[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + (prev[j] < curr[j - 1] ? (prev[j] < prev[j - 1] ? prev[j] : prev[j - 1]) : (curr[j - 1] < prev[j - 1] ? curr[j - 1] : prev[j - 1]));
            }
        }
        int *temp = prev;
        prev = curr;
        curr = temp;
    }
    int result = prev[lenT];
    free(prev);
    free(curr);
    return result <= K;
}

int main()
{
    int K;
    char S[500001], T[500001];
    scanf("%d", &K);
    scanf("%s", S);
    scanf("%s", T);
    if (editDistance(S, T, K))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

// TLE