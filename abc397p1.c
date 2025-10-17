#include <stdio.h>

int main()
{
    float X;
    scanf("%f", &X);
    if (X >= 38.0)
    {
        printf("1");
    }
    else if (X < 38.0 && X >= 37.5)
    {
        printf("2");
    }
    else
    {
        printf("3");
    }
    return 0;
}