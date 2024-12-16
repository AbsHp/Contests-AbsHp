#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int n[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d\n", &n[i]);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", n[i] - 1);
    }
    return 0;
}

// CodeForces Contest 993 P1