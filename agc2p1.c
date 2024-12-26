// #include <stdio.h>

// int main()
// {
//     long long a, b;
//     scanf("%lld %lld", &a, &b);
//     long long prod = 1;
//     for (long long i = a; i <= b; i++)
//     {
//         prod *= i;
//     }
//     if (prod > 0)
//     {
//         printf("Positive");
//     }
//     else if (prod < 0)
//     {
//         printf("Negative");
//     }
//     else
//     {
//         printf("Zero");
//     }
//     return 0;
// }

#include <stdio.h>

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a <= 0 && b >= 0)
    {
        printf("Zero");
    }
    else if (a > 0)
    {
        printf("Positive");
    }
    else
    {
        long long count = b - a + 1;
        if (count % 2 == 0)
        {
            printf("Positive");
        }
        else
        {
            printf("Negative");
        }
    }
    return 0;
}

// AtCoder Grand Contest 2 P1