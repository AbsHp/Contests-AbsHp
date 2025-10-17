#include <stdio.h>
#include <string.h>

int countTriples(const char *S)
{
    int n = strlen(S);
    int count = 0;
    for (int j = 1; j < n - 1; ++j)
    {
        for (int d = 1; j - d >= 0 && j + d < n; ++d)
        {
            int i = j - d;
            int k = j + d;
            if (S[i] == 'A' && S[j] == 'B' && S[k] == 'C')
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    char S[101];
    scanf("%s", S);
    printf("%d\n", countTriples(S));
    return 0;
}