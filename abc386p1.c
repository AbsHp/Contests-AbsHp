#include <stdio.h>

int canFormFullHouse(int cards[])
{
    int frequency[14] = {0};
    for (int i = 0; i < 4; i++)
    {
        frequency[cards[i]]++;
    }
    for (int i = 1; i <= 13; i++)
    {
        frequency[i]++;
        int countThree = 0, countTwo = 0;
        for (int j = 1; j <= 13; j++)
        {
            if (frequency[j] == 3)
                countThree++;
            if (frequency[j] == 2)
                countTwo++;
        }
        if (countThree == 1 && countTwo == 1)
        {
            return 1;
        }
        frequency[i]--;
    }
    return 0;
}

int main()
{
    int cards[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &cards[i]);
    }
    if (canFormFullHouse(cards))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}