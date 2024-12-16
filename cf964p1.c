#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &num[n]);
    }
    for (int i = 0; i < n; i++)
    {
        int dig1 = num[i] / 10;
        int dig2 = num[i] % 10;
        int sum = dig1 + dig2;
        printf("%d", sum);
    }

    return 0;
}

// CodeForces Contest 964 P1