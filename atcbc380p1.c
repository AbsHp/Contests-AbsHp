#include <stdio.h>

int main()
{
    char N[6];
    scanf("%s", N);
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < 6; i++)
    {
        if (N[i] == '1') count1++;
        if (N[i] == '2') count2++;
        if (N[i] == '3') count3++; 
    }
    if (count1 == 1 && count2 == 2 && count3 == 3)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

// AtCoder Beginner Contest 380 Problem 1