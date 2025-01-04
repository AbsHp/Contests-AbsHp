#include <stdio.h>

int main()
{
    int X, total_sum = 0, count_X = 0;
    scanf("%d", &X);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            int value = i * j;
            total_sum += value;
            if (value == X)
            {
                count_X++;
            }
        }
    }
    int result = total_sum - (count_X * X);
    printf("%d\n", result);
    return 0;
}