#include <stdio.h>
#include <string.h>

void transformString(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'p')
        {
            str[i] = 'q';
        }
        else if (str[i] == 'q')
        {
            str[i] = 'p';
        }
    }
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    printf("%s\n", str);
}

int main()
{
    int t;
    scanf("%d", &t);
    char n[t][101];
    for (int i = 0; i < t; i++)
    {
        scanf("%100s", n[i]);
    }
    for (int i = 0; i < t; i++)
    {
        transformString(n[i]);
    }
    return 0;
}

// CodeForces Contest 993 P2