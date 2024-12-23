#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

int compare(const void *a, const void *b)
{
    return (*(long long *)a - *(long long *)b);
}

int main()
{
    int t;
    scanf("%d", &t);
    long long result[t];
    for (int j = 0; j < t; j++)
    {
        int n;
        long long x, y;
        scanf("%d %lld %lld", &n, &x, &y);
        long long a[n];
        long long total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            total_sum += a[i];
        }
        qsort(a, n, sizeof(long long), compare);
        long long lower_bound = total_sum - y;
        long long upper_bound = total_sum - x;
        result[j] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            long long target_low = lower_bound - a[i];
            long long target_high = upper_bound - a[i];
            int left = i + 1, right = n - 1;
            int lower = -1, upper = -1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (a[mid] >= target_low)
                {
                    lower = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            left = i + 1;
            right = n - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (a[mid] <= target_high)
                {
                    upper = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            if (lower != -1 && upper != -1 && lower <= upper)
            {
                result[j] += (upper - lower + 1);
            }
        }
    }
    for (int j = 0; j < t; j++)
    {
        printf("%lld\n", result[j]);
    }
    return 0;
}

// Accepted YAY!