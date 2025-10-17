#include <stdio.h>
#include <string.h>

char find_unique_char(const char *s)
{
    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        count[s[i] - 'a']++;
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (count[s[i] - 'a'] == 1)
        {
            return s[i];
        }
    }
    return '\0';
}

int main()
{
    char s[11];
    scanf("%s", s);
    char unique = find_unique_char(s);
    printf("%c\n", unique);
    return 0;
}