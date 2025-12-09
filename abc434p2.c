#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int A[105], B[105];
    int count[105] = {0};
    int sum[105] = {0};
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
        int type = A[i];
        sum[type] += B[i];
        count[type]++;
    }
    for (int k = 1; k <= M; k++)
    {
        double avg = (double)sum[k] / count[k];
        printf("%.6f\n", avg);
    }
    return 0;
}