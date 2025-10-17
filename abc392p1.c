#include <stdio.h>

int main()
{
    int A1, A2, A3;
    scanf("%d %d %d", &A1, &A2, &A3);
    if ((A1 *A2 == A3) || (A2 *A3 == A1) || (A3 *A1 == A2))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}