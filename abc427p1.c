#include <stdio.h>
#include <string.h>

int main()
{
    char S[101];
    scanf("%s", S);
    int len = strlen(S);
    int mid = len / 2;
    for (int i = 0; i < len; i++)
    {
        if (i != mid)
        {
            printf("%c", S[i]);
        }
    }
    printf("\n");
    return 0;
}