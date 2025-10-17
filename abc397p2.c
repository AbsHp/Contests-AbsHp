#include <stdio.h>
#include <string.h>

int minInsertionsToMatchPattern(char *S)
{
    int n = strlen(S);
    int insertions = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (S[i] != 'i')
            {
                insertions++;
            }
        }
        else
        {
            if (S[i] != 'o')
            {
                insertions++;
            }
        }
    }
    if (n % 2 != 0)
    {
        insertions++;
    }
    return insertions;
}

int main()
{
    char S[101];
    scanf("%s", S);
    int result = minInsertionsToMatchPattern(S);
    printf("%d\n", result);
    return 0;
}

// WA :(