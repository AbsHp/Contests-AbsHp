#include <stdio.h>
#include <stdlib.h>

int countGoodPrefixes(int a[], int n)
{
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        for (int j = 0; j <= i; j++)
        {
            if (a[j] == sum - a[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    int *result = (int *)malloc(t * sizeof(int));
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int *a = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        result[i] = countGoodPrefixes(a, n);
        free(a);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}

// CodeForces Contest 952 P3
// Still giving TLE please help