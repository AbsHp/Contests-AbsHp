#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int prod = 1;
    for (int i = a; i <= b; i++)
    {
        prod *= i;
    }
    if (prod > 0)
    {
        printf("Positive");
    }
    else if (prod < 0)
    {
        printf("Negative");
    }
    else
    {
        printf("Zero");
    }
    return 0;
}

// AtCoder Grand Contest 2 P1