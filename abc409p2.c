#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max_x = 0;
    for (int x = 0; x <= n; x++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= x)
            {
                count++;
            }
        }
        if (count >= x)
        {
            if (x > max_x)
            {
                max_x = x;
            }
        }
    }
    printf("%d\n", max_x);
    return 0;
}