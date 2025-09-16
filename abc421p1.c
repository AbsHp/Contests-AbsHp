#include <stdio.h>
#include <string.h>

int main()
{
    int N, X;
    char S[105][15];
    char Y[15];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", S[i]);
    }
    scanf("%d", &X);
    scanf("%s", Y);
    if (strcmp(S[X], Y) == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}