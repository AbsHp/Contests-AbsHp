#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if ((A == 5 && B == 5 && C == 7) || (A == 5 && B == 7 && C == 5) || (A == 7 && B == 5 && C == 5))
    {  
        printf("YES"); 
    }
    else
    {
        printf("NO");
    }
    return 0;
}

// AtCoder Beginner Contest 42 Problem 1