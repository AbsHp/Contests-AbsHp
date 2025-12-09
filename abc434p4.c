#include <stdio.h>

#define MAX 2002

int diff[MAX][MAX];
int cover[MAX][MAX];
int pref1[MAX][MAX];
long long total_uncovered;

int main()
{
    int N;
    scanf("%d", &N);
    int U[N], D[N], L[N], R[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &U[i], &D[i], &L[i], &R[i]);
        diff[U[i]][L[i]] += 1;
        diff[U[i]][R[i] + 1] -= 1;
        diff[D[i] + 1][L[i]] -= 1;
        diff[D[i] + 1][R[i] + 1] += 1;
    }
    for (int r = 1; r <= 2000; r++)
    {
        for (int c = 1; c <= 2000; c++)
        {
            diff[r][c] += diff[r - 1][c] + diff[r][c - 1] - diff[r - 1][c - 1];
            cover[r][c] = diff[r][c];
        }
    }
    for (int r = 1; r <= 2000; r++)
    {
        for (int c = 1; c <= 2000; c++)
        {
            int is1 = (cover[r][c] == 1);
            pref1[r][c] = is1 + pref1[r - 1][c] + pref1[r][c - 1] - pref1[r - 1][c - 1];
        }
    }
    total_uncovered = 0;
    for (int r = 1; r <= 2000; r++)
        for (int c = 1; c <= 2000; c++)
            if (cover[r][c] == 0)
                total_uncovered++;
    for (int i = 0; i < N; i++)
    {
        int u = U[i], d = D[i], l = L[i], r = R[i];
        int c1 = pref1[d][r];
        int c2 = pref1[u - 1][r];
        int c3 = pref1[d][l - 1];
        int c4 = pref1[u - 1][l - 1];
        int exactly1 = c1 - c2 - c3 + c4;
        long long ans = total_uncovered + exactly1;
        printf("%lld\n", ans);
    }
    return 0;
}