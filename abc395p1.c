#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int isincreasing = 1;
    for (int i = 1; i < N; i++)
    {
        if (A[i - 1] >= A[i])
        {
            isincreasing = 0;
            break;
        }
    }
    if (isincreasing == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}