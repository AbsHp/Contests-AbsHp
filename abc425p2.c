#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N], P[N];
    bool used[N + 1];
    for (int i = 0; i <= N; i++)
        used[i] = false;
    bool invalid = false;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] != -1)
        {
            if (used[A[i]])
            {
                invalid = true;
            }
            used[A[i]] = true;
            P[i] = A[i];
        }
    }
    if (invalid)
    {
        printf("No\n");
        return 0;
    }
    int num = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == -1)
        {
            while (used[num])
                num++;
            P[i] = num;
            used[num] = true;
        }
    }
    printf("Yes\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", P[i]);
    }
    printf("\n");
    return 0;
}