#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if ((A + B == C) || (A + C == B) || (B + C == A) || (A == B == C))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}

// AtCoder Beginner Contest 385 P1