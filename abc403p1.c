#include <stdio.h>

int main()
{
    int N;
    scanf("%d\n", &N);
    int a[N];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        if (i % 2 == 0)
        {
            sum = sum + a[i];
        }
    }
    printf("%d", sum);
    return 0;
}