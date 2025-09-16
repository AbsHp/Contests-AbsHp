#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if ((a > c) || ((a == c) && (b > d)))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}