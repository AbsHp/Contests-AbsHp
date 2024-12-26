#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char w[101];
    char uniqueAlphabets[26];
    int counts[26] = {0};
    int uniqueCount = 0;
    int result = 0;
    fgets(w, sizeof(w), stdin);
    for (int i = 0; w[i] != '\0'; i++)
    {
        if (isalpha(w[i]))
        {
            char ch = tolower(w[i]);
            int found = 0;
            for (int j = 0; j < uniqueCount; j++)
            {
                if (uniqueAlphabets[j] == ch)
                {
                    found = 1;
                    counts[j]++;
                    break;
                }
            }
            if (!found)
            {
                uniqueAlphabets[uniqueCount] = ch;
                counts[uniqueCount] = 1;
                uniqueCount++;
            }
        }
    }
    for (int i = 0; i < uniqueCount; i++)
    {
        if (counts[i] % 2 == 0)
        {
            result += 1;
        }
    }
    if (result == uniqueCount)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}

// AtCoder Beginner Contest 44 P2