#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char t[n + 1], a[n + 1];
    getchar();
    scanf("%s", t);
    scanf("%s", a);
    for (int i = 0; i < n; i++)
    {
        if ((t[i] == 'o') && (a[i] == 'o'))
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}