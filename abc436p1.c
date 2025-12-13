#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char S[105];
    scanf("%d", &N);
    scanf("%s", S);
    int len = strlen(S);
    for (int i = 0; i < N - len; i++)
    {
        printf("o");
    }
    printf("%s\n", S);
    return 0;
}