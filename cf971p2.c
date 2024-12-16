#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char rows[n][5];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", rows[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (rows[i][j] == '#')
                {
                    printf("%d", j + 1);
                    if (i > 0)
                        printf(" ");
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

// CodeForces Contest 971 P2