#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    char a[t][4], b[t][4];
    for (int i = 0; i < t; i++)
    {
        scanf("%s %s", a[i], b[i]);
    }
    for (int i = 0; i < t; i++)
    {
        char c;
        c = a[i][0];
        a[i][0] = b[i][0];
        b[i][0] = c;
        printf("%s %s\n", a[i], b[i]);
    }
    return 0;
}

// CodeForces Contest 952 P1