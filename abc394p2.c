#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

int main()
{
    int N;
    scanf("%d", &N);
    char *S[N];
    for (int i = 0; i < N; i++)
    {
        S[i] = (char *)malloc(1000 * sizeof(char));
        scanf("%s", S[i]);
    }
    qsort(S, N, sizeof(char *), compare);
    char result[10000] = "";
    for (int i = 0; i < N; i++)
    {
        strcat(result, S[i]);
    }
    printf("%s\n", result);
    for (int i = 0; i < N; i++)
    {
        free(S[i]);
    }
    return 0;
}