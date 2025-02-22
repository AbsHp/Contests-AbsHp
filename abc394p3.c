#include <stdio.h>
#include <string.h>

void replace_WA_with_AC(char *S)
{
    char *pos;
    while ((pos = strstr(S, "WA")) != NULL)
    {
        pos[0] = 'A';
        pos[1] = 'C';
    }
}

int main()
{
    char S[300005];
    scanf("%s", S);
    replace_WA_with_AC(S);
    printf("%s\n", S);
    return 0;
}