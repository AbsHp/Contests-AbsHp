#include <stdio.h>

int main()
{
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    if (((A == B) && (C == D) && (A != C)) || ((A == C) && (B == D) && (A != B)) || ((A == D) && (C == B) && (A != B)) || ((A == B) && (B == C) && (C != D)) || ((B == C) && (C == D) && (D != A)) || ((C == D) && (D == A) && (A != B)))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}