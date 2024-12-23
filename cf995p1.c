// #include <stdio.h>

// int maxDifference(int n, int a[], int b[])
// {
//     int max_diff = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int monocarp_score = 0, stereocarp_score = 0;
//         for (int j = i; j < n; j++)
//         {
//             monocarp_score += a[j];
//             if (j + 1 < n)
//             {
//                 stereocarp_score += b[j + 1];
//             }
//         }
//         int diff = monocarp_score - stereocarp_score;
//         if (diff > max_diff)
//         {
//             max_diff = diff;
//         }
//     }
//     return max_diff;
// }

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     int result[t];
//     for (int i = 0; i < t; i++)
//     {
//         int n;
//         scanf("%d", &n);
//         int a[n], b[n];
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &a[j]);
//         }
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &b[j]);
//         }
//         result[i] = maxDifference(n, a, b);
//     }
//     for (int i = 0; i < t; i++)
//     {
//         printf("%d\n", result[i]);
//     }
//     return 0;
// }

#include <stdio.h>

#define MAX_N 100

int main()
{
    int t;
    scanf("%d", &t);
    int result[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[MAX_N], b[MAX_N];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }
        int dp[MAX_N + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i];
            if (i + 1 < n)
            {
                dp[i + 1] = (dp[i] + a[i] - b[i + 1]) > dp[i + 1] ? (dp[i] + a[i] - b[i + 1]) : dp[i + 1];
            }
            else
            {
                dp[i + 1] = dp[i] + a[i];
            }
        }
        result[i] = dp[n];
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}

// CodeForces Contest 995 P1
// Accepted YAY!