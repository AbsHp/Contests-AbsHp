#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_snake_number(long long num)
{
    char str[20];
    sprintf(str, "%lld", num);
    int top_digit = str[0] - '0';
    int len = strlen(str);
    for (int i = 1; i < len; i++)
    {
        int digit = str[i] - '0';
        if (digit >= top_digit)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long L, R;
    long long snake_count = 0;
    scanf("%lld %lld", &L, &R);
    for (long long i = L; i <= R; i++)
    {
        if (is_snake_number(i))
        {
            snake_count++;
        }
    }
    printf("%lld\n", snake_count);
    return 0;
}

// TLE for some cases