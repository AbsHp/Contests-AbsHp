#include <stdio.h>
#include <string.h>

int main()
{
    char N[4];
    scanf("%3s", N);
    printf("%c%c%c %c%c%c", N[1], N[2], N[0], N[2], N[0], N[1]);
    return 0;
}

// AtCoder Beginner Contest 379 Problem 1