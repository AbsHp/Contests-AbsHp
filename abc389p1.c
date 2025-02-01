#include <stdio.h>

int main()
{
    char S[3];
    scanf("%s", S);
    int product = 1;
    product = (S[0] - '0') * (S[2] - '0');
    printf("%d", product);
    return 0;
}