#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int A[6];
double memo[3][46656];
char seen[3][46656];
double pow_1_6[6];

int encode_kept(const int kept[6])
{
    int code = 0;
    int base = 1;
    for (int i = 0; i < 6; i++)
    {
        code += kept[i] * base;
        base *= 6;
    }
    return code;
}

double solve_rec(int kept[6], int r);

double best_keep_choice_and_value(const int kept[6], const int c[6], int r)
{
    int new_keep[6];
    double best = -1.0;
    int max_choice[6];
    for (int i = 0; i < 6; i++)
        max_choice[i] = c[i];
    for (int i = 0; i < 6; i++)
        new_keep[i] = 0;
    int done = 0;
    while (!done)
    {
        int next_kept[6];
        for (int i = 0; i < 6; i++)
            next_kept[i] = kept[i] + new_keep[i];
        double val = solve_rec(next_kept, r - 1);
        if (val > best)
            best = val;
        int pos = 0;
        while (pos < 6)
        {
            new_keep[pos]++;
            if (new_keep[pos] <= max_choice[pos])
                break;
            new_keep[pos] = 0;
            pos++;
        }
        if (pos == 6)
            done = 1;
    }
    return best;
}

double simulate_roll_and_evaluate(const int kept[6], int r)
{
    int sum_kept = 0;
    for (int i = 0; i < 6; i++)
        sum_kept += kept[i];
    int m = 5 - sum_kept;
    if (m == 0)
    {
        if (r == 0)
        {
            double best = 0.0;
            for (int v = 0; v < 6; v++)
            {
                double sc = (double)A[v] * (double)kept[v];
                if (sc > best)
                    best = sc;
            }
            return best;
        }
        else
        {
            return solve_rec((int *)kept, r - 1);
        }
    }

    double expectation = 0.0;
    int c[6];
    for (int i = 0; i < 6; i++)
        c[i] = 0;
    int faces[5];
    for (int i = 0; i < m; i++)
        faces[i] = 0;
    int done = 0;
    while (!done)
    {
        for (int i = 0; i < 6; i++)
            c[i] = 0;
        for (int i = 0; i < m; i++)
            c[faces[i]]++;
        double prob = pow_1_6[m];
        if (r == 0)
        {
            double best = 0.0;
            for (int v = 0; v < 6; v++)
            {
                double sc = (double)A[v] * (double)(kept[v] + c[v]);
                if (sc > best)
                    best = sc;
            }
            expectation += prob * best;
        }
        else
        {
            double best_after_keep = best_keep_choice_and_value(kept, c, r);
            expectation += prob * best_after_keep;
        }
        int pos = 0;
        while (pos < m)
        {
            faces[pos]++;
            if (faces[pos] < 6)
                break;
            faces[pos] = 0;
            pos++;
        }
        if (pos == m)
            done = 1;
    }
    return expectation;
}

double solve_rec(int kept_in[6], int r)
{
    int code = encode_kept(kept_in);
    if (seen[r][code])
        return memo[r][code];
    seen[r][code] = 1;
    double val = simulate_roll_and_evaluate(kept_in, r);
    memo[r][code] = val;
    return val;
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        if (scanf("%d", &A[i]) != 1)
        {
            fprintf(stderr, "Expected 6 integers A1..A6\n");
            return 1;
        }
    }
    int allsame = 1;
    for (int i = 1; i < 6; i++)
    {
        if (A[i] != A[0])
        {
            allsame = 0;
            break;
        }
    }
    if (allsame)
    {
        printf("%.10f\n", 5.0 * A[0]);
        return 0;
    }
    pow_1_6[0] = 1.0;
    double inv6 = 1.0 / 6.0;
    for (int i = 1; i <= 5; i++)
        pow_1_6[i] = pow_1_6[i - 1] * inv6;
    memset(seen, 0, sizeof(seen));
    int kept0[6] = {0, 0, 0, 0, 0, 0};
    double ans = solve_rec(kept0, 2);
    printf("%.10f\n", ans);
    return 0;
}

// WA :(