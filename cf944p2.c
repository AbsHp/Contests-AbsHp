#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool rearrangeString(char *s, char *result)
{
    int len = strlen(s);
    strcpy(result, s);

    for (int i = 0; i < len - 1; i++)
    {
        if (result[i] != result[i + 1])
        {
            swap(&result[i], &result[i + 1]);
            return strcmp(s, result) != 0;
        }
    }

    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    char s[t][11];
    char r[t][11];
    for (int i = 0; i < t; i++)
    {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < t; i++)
    {
        if (rearrangeString(s[i], r[i]))
        {
            printf("YES\n%s\n", r[i]);
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

// CodeForces Contest 944 P2