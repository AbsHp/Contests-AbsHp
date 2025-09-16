#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 400005

int main()
{
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    int offset = 200000;
    int *freq = (int *)calloc(MAX, sizeof(int));
    long long count = 0;
    for (int j = 0; j < N; ++j)
    {
        int right = j - A[j];
        if (right + offset >= 0 && right + offset < MAX)
            count += freq[right + offset];
        int left = j + A[j];
        if (left + offset >= 0 && left + offset < MAX)
            freq[left + offset]++;
    }
    printf("%lld\n", count);
    free(A);
    free(freq);
    return 0;
}