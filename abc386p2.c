#include <stdio.h>
#include <string.h>

int minButtonPresses(char *S)
{
    int length = strlen(S);
    int presses = 0;
    for (int i = 0; i < length;)
    {
        if (i < length - 1 && S[i] == '0' && S[i + 1] == '0')
        {
            presses++;
            i += 2;
        }
        else
        {
            presses++;
            i++;
        }
    }
    return presses;
}

int main()
{
    char S[1001];
    scanf("%s", S);
    int result = minButtonPresses(S);
    printf("%d", result);
    return 0;
}