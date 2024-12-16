#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", b[i] - a[i]);
    }
    return 0;
}

// CodeForces Contest 971 P1