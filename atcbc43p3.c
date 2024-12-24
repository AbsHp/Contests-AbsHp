#include <stdio.h>
#include <limits.h>

int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    int minValue = INT_MAX, maxValue = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < minValue)
            minValue = a[i];
        if (a[i] > maxValue)
            maxValue = a[i];
    }
    int minCost = INT_MAX;
    for (int target = minValue; target <= maxValue; target++)
    {
        int currentCost = 0;
        for (int i = 0; i < N; i++)
        {
            int diff = a[i] - target;
            currentCost += diff * diff;
        }
        if (currentCost < minCost)
            minCost = currentCost;
    }
    printf("%d\n", minCost);
    return 0;
}

// AtCoder Beginner Contest 43 P3