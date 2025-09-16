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
    int x;
    scanf("%d", &x);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            found = 1;
            break;
        }
    }
    if (found)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}