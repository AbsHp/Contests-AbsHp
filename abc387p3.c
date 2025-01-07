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

// #include <stdio.h>
// #include <string.h>

// long long isSnakeNumber(long long num)
// {
//     char str[20];
//     sprintf(str, "%lld", num);
//     int top_digit = str[0] - '0';
//     for (int i = 1; str[i] != '\0'; i++)
//     {
//         if (top_digit <= str[i] - '0')
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     long long L, R;
//     scanf("%lld %lld", &L, &R);
//     long long int count = 0;
//     for (long long i = L; i <= R; i++)
//     {
//         if (isSnakeNumber(i))
//         {
//             count++;
//         }
//     }
//     printf("%lld\n", count);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 19
#define INF 10

long long dp[MAX_DIGITS][2][10][10];
char number[MAX_DIGITS];

long long countSnakeNumbers(int pos, int isTight, int maxDigit, int minDigit)
{
    if (pos == strlen(number))
    {
        return (maxDigit > minDigit) ? 1 : 0;
    }
    if (dp[pos][isTight][maxDigit][minDigit] != -1)
    {
        return dp[pos][isTight][maxDigit][minDigit];
    }
    int limit = isTight ? number[pos] - '0' : 9;
    long long result = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        int newMax = (digit > maxDigit) ? digit : maxDigit;
        int newMin = (digit < minDigit) ? digit : minDigit;
        result += countSnakeNumbers(pos + 1, isTight && (digit == limit), newMax, newMin);
    }
    dp[pos][isTight][maxDigit][minDigit] = result;
    return result;
}
long long countUpTo(long long num)
{
    snprintf(number, sizeof(number), "%lld", num);
    memset(dp, -1, sizeof(dp));
    return countSnakeNumbers(0, 1, -1, INF);
}

int main()
{
    long long L, R;
    scanf("%lld %lld", &L, &R);
    long long result = countUpTo(R) - countUpTo(L - 1);
    printf("%lld\n", result);
    return 0;
}

// TLE