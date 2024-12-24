// #include <stdio.h>

// #define INF 1000000000

// int max_height(int N, int buildings[][2])
// {
//     int max_h = -1;
//     double last_slope = -INF;
//     for (int i = 0; i < N; i++)
//     {
//         int x = buildings[i][0];
//         int h = buildings[i][1];
//         double current_slope = (double)h / x;
//         if (current_slope < last_slope)
//         {
//             max_h = (max_h > h) ? max_h : h;
//         }
//         last_slope = current_slope;
//     }
//     return max_h;
// }

// int main()
// {
//     int N;
//     scanf("%d", &N);
//     int buildings[N][2];
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d %d", &buildings[i][0], &buildings[i][1]);
//     }
//     int result = max_height(N, buildings);
//     printf("%d\n", result);
//     return 0;
// }

#include <stdio.h>

#define MAXN 200000

typedef struct
{
    long long x, h;
} Building;

Building buildings[MAXN];

int N;

int can_see_all_at_height(long long h)
{
    long long max_slope = -1e18;
    for (int i = 0; i < N; i++)
    {
        long long slope = (buildings[i].h - h) * 1LL * buildings[i].x;
        if (slope < max_slope)
        {
            return 0;
        }
        max_slope = slope;
    }
    return 1;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &buildings[i].x, &buildings[i].h);
    }
    long long low = 0, high = 1e9 + 1, mid, result = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (can_see_all_at_height(mid))
        {
            low = mid + 1;
        }
        else
        {
            result = mid;
            high = mid - 1;
        }
    }
    printf("%lld\n", result);
    return 0;
}

// WA
// AtCoder Beginner Contest 385 P6