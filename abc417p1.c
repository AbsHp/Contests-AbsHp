#include <stdio.h>
#include <string.h>

int main()
{
    int N, A, B;
    char S[1001];
    scanf("%d %d %d", &N, &A, &B);
    scanf("%s", S);
    for (int i = A; i < N - B; i++)
    {
        putchar(S[i]);
    }
    putchar('\n');
    return 0;
}