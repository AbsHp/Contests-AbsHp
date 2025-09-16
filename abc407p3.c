#include <stdio.h>
#include <string.h>

int main()
{
    char S[500001];
    scanf("%s", S);
    int len = strlen(S);
    int max_k = 0;
    for (int i = 0; i < len; ++i)
    {
        int c = S[i] - '0';
        int k;
        if (c == 0)
        {
            k = 0;
        }
        else
        {
            k = 10 - c;
        }
        if (k > max_k)
        {
            max_k = k;
        }
    }
    printf("%d\n", len + max_k);
    return 0;
}