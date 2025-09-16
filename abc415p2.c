#include <stdio.h>
#include <string.h>

int main()
{
    char S[1001];
    int positions[1000];
    int count = 0;
    scanf("%s", S);
    int len = strlen(S);
    for (int i = 0; i < len; i++)
    {
        if (S[i] == '#')
        {
            positions[count++] = i + 1;
        }
    }
    for (int i = 0; i < count; i += 2)
    {
        printf("%d,%d\n", positions[i], positions[i + 1]);
    }
    return 0;
}