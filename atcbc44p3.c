#include <stdio.h>

void findSubsets(int arr[], int n, int index, int currentSum, int count, double targetAvg, long long *result)
{
    if (count > 0 && (double)currentSum / count == targetAvg)
    {
        (*result)++;
    }
    for (int i = index; i < n; i++)
    {
        findSubsets(arr, n, i + 1, currentSum + arr[i], count + 1, targetAvg, result);
    }
}

int countSubsetsWithAverage(int arr[], int n, double targetAvg)
{
    long long result = 0;
    findSubsets(arr, n, 0, 0, 0, targetAvg, &result);
    return result;
}

int main()
{
    int N, A;
    scanf("%d %d", &N, &A);
    int x[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
    }
    long long result = countSubsetsWithAverage(x, N, A);
    printf("%lld", result);
    return 0;
}

// - (TLE on some cases)
// AtCoder Beginner Contest 44 P3