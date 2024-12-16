#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int main()
{
    long long int t;
    scanf("%lld", &t);
    long long *m = (long long *)malloc(t * sizeof(long long));
    long long *a = (long long *)malloc(t * sizeof(long long));
    long long *b = (long long *)malloc(t * sizeof(long long));
    long long *c = (long long *)malloc(t * sizeof(long long));
    long long *seatedInRow1 = (long long *)malloc(t * sizeof(long long));
    long long *seatedInRow2 = (long long *)malloc(t * sizeof(long long));
    long long *remainingRow1 = (long long *)malloc(t * sizeof(long long));
    long long *remainingRow2 = (long long *)malloc(t * sizeof(long long));
    long long *seatedNoPreference = (long long *)malloc(t * sizeof(long long));
    long long *totalSeated = (long long *)malloc(t * sizeof(long long));
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld %lld %lld", &m[i], &a[i], &b[i], &c[i]);
        seatedInRow1[i] = min(a[i], m[i]);
        seatedInRow2[i] = min(b[i], m[i]);
        remainingRow1[i] = m[i] - seatedInRow1[i];
        remainingRow2[i] = m[i] - seatedInRow2[i];
        seatedNoPreference[i] = min(c[i], remainingRow1[i] + remainingRow2[i]);
        totalSeated[i] = seatedInRow1[i] + seatedInRow2[i] + seatedNoPreference[i];
    }
    for (int i = 0; i < t; i++)
    {
        printf("%lld\n", totalSeated[i]);
    }
    free(m);
    free(a);
    free(b);
    free(c);
    free(seatedInRow1);
    free(seatedInRow2);
    free(remainingRow1);
    free(remainingRow2);
    free(seatedNoPreference);
    free(totalSeated);
    return 0;
}