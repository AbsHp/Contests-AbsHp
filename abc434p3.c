#include <stdio.h>

#define ll long long

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        ll H;
        scanf("%d %lld", &N, &H);
        ll lo = H, hi = H;
        ll prev_t = 0;
        int possible = 1;
        for (int i = 0; i < N; i++)
        {
            ll t, l, u;
            scanf("%lld %lld %lld", &t, &l, &u);

            ll dt = t - prev_t;
            lo -= dt;
            hi += dt;
            if (lo < 1)
                lo = 1;
            if (lo < l)
                lo = l;
            if (hi > u)
                hi = u;
            if (lo > hi)
                possible = 0;
            prev_t = t;
        }
        printf(possible ? "Yes\n" : "No\n");
    }
    return 0;
}