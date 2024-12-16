#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int n[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n[i]);
    }
    for (int i = 0; i < t; i++)
    {
        if (n[i] == 3)
        {
            printf("3\n");
        }
        else
        {
            printf("2\n");
        }
    }
    return 0;
}

// CodeForces Contest 952 P2