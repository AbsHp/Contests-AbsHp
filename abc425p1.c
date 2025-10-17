#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (i%2 != 0)
        {
            sum = sum - i*i*i;
        }
        else
        {
            sum = sum + i*i*i;
        }
    }
    printf("%d", sum);
    return 0;
}