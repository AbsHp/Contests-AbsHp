#include <stdio.h>

int main()
{
    int N, K, X, Y;
    scanf("%d \n%d \n%d \n%d", &N, &K, &X, &Y);
    int fee = 0;
    for (int i = 0; i < N; i++)
    {
        if (i < K)
        {
            fee = fee + X;
        }
        else
        {
            fee = fee + Y;
        }
    }
    printf("%d", fee);
    return 0;
}