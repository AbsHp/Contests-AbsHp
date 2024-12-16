#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int a1[t], b1[t], a2[t], b2[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d", &a1[i], &a2[i], &b1[i], &b2[i]);
    }
    for (int i = 0; i < t; i++)
    {
        int count = 0;
        if (a1[i] > b1[i] && a2[i] > b2[i])
        {
            count = count + 2;
        }
        if (a1[i] > b2[i] && a2[i] > b1[i])
        {
            count = count + 2;
        }
        if (a1[i] == b1[i] && a2[i] > b2[i])
        {
            count = count + 2;
        }
        if (a1[i] > b1[i] && a2[i] == b2[i])
        {
            count = count + 2;
        }
        if (a1[i] == b2[i] && a2[i] > b1[i])
        {
            count = count + 2;
        }
        if (a1[i] > b2[i] && a2[i] == b1[i])
        {
            count = count + 2;
        }
        printf("%d\n", count);
    }
    return 0;
}

// CodeForces Contest 964 P2