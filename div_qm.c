#include <stdio.h>

int main()
{
    int t, p;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &p);
        if (p <= 1399)
        {
            printf("Division 4\n");
        }
        else if (p >= 1400 && p <= 1599)
        {
            printf("Division 3\n");
        }
        else if (p >= 1600 && p <= 1899)
        {
            printf("Division 2\n");
        }
        else
        {
            printf("Division 1\n");
        }   
    }
    return 0;
}