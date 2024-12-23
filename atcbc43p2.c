#include <stdio.h>
#include <string.h>

#define MAX_LEN 15

int main()
{
    char s[MAX_LEN + 1];
    char result[MAX_LEN + 1];
    int resultIndex = 0;
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '0' || s[i] == '1')
        {
            result[resultIndex++] = s[i];
        }
        else if (s[i] == 'B')
        {
            if (resultIndex > 0)
            {
                resultIndex--;
            }
        }
    }
    result[resultIndex] = '\0';
    printf("%s\n", result);
    return 0;
}

// AtCoder Beginner Contest 43 P2