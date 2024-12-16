#include <stdio.h>
#include <stdlib.h>

int minMoves(int x, int y, int k)
{
    x = abs(x);
    y = abs(y);
    int moves = 0;
    int distanceX = 0;
    int distanceY = 0;

    while (distanceX < x || distanceY < y)
    {
        if (moves % 2 == 0)
        {
            int moveX = (x - distanceX > k) ? k : x - distanceX;
            distanceX += moveX;
        }
        else
        {
            int moveY = (y - distanceY > k) ? k : y - distanceY;
            distanceY += moveY;
        }
        moves++;
    }
    return moves;
}

int main()
{
    int t;
    scanf("%d", &t);
    int x[t], y[t], k[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &x[i], &y[i], &k[i]);
    }
    for (int i = 0; i < t; i++)
    {
        int result = minMoves(x[i], y[i], k[i]);
        printf("%d\n", result);
    }
    return 0;
}