#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X, Y;
    scanf("%d %d", &X, &Y);
    int favorable = 0;
    int total = 36;
    for (int die1 = 1; die1 <= 6; die1++)
    {
        for (int die2 = 1; die2 <= 6; die2++)
        {
            int sum = die1 + die2;
            int diff = abs(die1 - die2);
            if (sum >= X || diff >= Y)
            {
                favorable++;
            }
        }
    }
    double probability = (double)favorable / total;
    printf("%.10f\n", probability);
    return 0;
}