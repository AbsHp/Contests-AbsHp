#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int is_unbalanced(const char *str, int start, int end)
{
    int freq[26] = {0};
    int length = end - start + 1;
    for (int i = start; i <= end; i++)
    {
        freq[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > length / 2)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char s[MAX_LEN + 1];
    scanf("%s", s);
    int n = strlen(s);
    for (int len = 2; len <= 3; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            if (is_unbalanced(s, i, i + len - 1))
            {
                printf("%d %d\n", i + 1, i + len);
                return 0;
            }
        }
    }
    printf("-1 -1\n");
    return 0;
}

// AtCoder Regular Contest 59 P2