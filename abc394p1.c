#include <stdio.h>
#include <string.h>

void filter_twos(const char *S, char *result)
{
    int j = 0;
    for (int i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == '2')
        {
            result[j++] = S[i];
        }
    }
    result[j] = '\0';
}

int main()
{
    char S[1000], result[1000];
    scanf("%s", S);
    filter_twos(S, result);
    printf("%s", result);
    return 0;
}