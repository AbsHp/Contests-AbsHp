#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10
#define MAXK 5
#define MAX_LEN 11
#define MAX_COMBO 100000
#define MAX_STRING 51

char *S[MAXN];
char result[MAX_COMBO][MAX_STRING];
int N, K;
long long total = 0;

void generate(int depth, char *current)
{
    if (depth == K)
    {
        strcpy(result[total++], current);
        return;
    }
    char temp[MAX_STRING];
    for (int i = 0; i < N; ++i)
    {
        strcpy(temp, current);
        strcat(temp, S[i]);
        generate(depth + 1, temp);
    }
}

int cmp(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main()
{
    int X;
    scanf("%d %d %d", &N, &K, &X);
    for (int i = 0; i < N; ++i)
    {
        S[i] = (char *)malloc(MAX_LEN * sizeof(char));
        scanf("%s", S[i]);
    }
    char current[MAX_STRING] = "";
    generate(0, current);
    qsort(result, total, sizeof(result[0]), cmp);
    printf("%s\n", result[X - 1]);
    for (int i = 0; i < N; ++i)
        free(S[i]);
    return 0;
}