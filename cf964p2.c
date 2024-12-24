#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int s1[t], s1[t], l1[t], l2[t];
    int ways = 0;
    for (s1 = 1; s1 <= 10; s1++)
    {
        for (s2 = 1; s2 <= 10; s2++)
        {
            for (l1 = 1; l1 <= 10; l1++)
            {
                for (l2 = 1; l2 <= 10; l2++)
                {
                    int suneet_wins = 0, slavic_wins = 0;
                    if (s1 > l1)
                        suneet_wins++;
                    else if (s1 < l1)
                        slavic_wins++;
                    if (s2 > l2)
                        suneet_wins++;
                    else if (s2 < l2)
                        slavic_wins++;
                    if (suneet_wins > slavic_wins)
                        ways++;
                }
            }
        }
    }
    printf("%d\n", ways);

    return 0;
}

// Codeforces Contest 964 P2
// Errors Still