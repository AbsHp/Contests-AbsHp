#include <stdio.h>

int main()
{
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    char arr[n];
    scanf("%s", arr);
    for (int i = l - 1; i < r; i++)
    {
        if (arr[i] == 'x')
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}