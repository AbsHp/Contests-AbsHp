#include <stdio.h>

int main()
{
    int N, C;
    scanf("%d %d\n", &N, &C);
    int lastcandice_nuts = 0;
    int n = 1;
    int T;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &T);
        if (T >= lastcandice_nuts + C)
        {
            n = n + 1;
            lastcandice_nuts = T;
        }
    }
    printf("%d", n);
    return 0;
}