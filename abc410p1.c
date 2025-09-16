#include <stdio.h>

int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        if (k <= a[i])
        {
            sum += 1;
        }
    }
    printf("%d", sum);
    return 0;
}