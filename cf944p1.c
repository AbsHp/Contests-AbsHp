#include <stdio.h>
 
int main()
{
    int t, x, y;
    scanf("%d\n", &t);
    for (int i; i < t; i++)
    {
        scanf("%d %d\n", &x, &y);
        if (x >= y)
        {
            printf("%d %d\n", y, x);
        }
        else if (x < y)
        {
          printf("%d %d\n", x, y);
        }
    }
    return 0;
}

// CodeForces Contest 944 P1