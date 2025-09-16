#include <stdio.h>
#include <string.h>

int main()
{
    char S[1001];
    char T[1001];
    scanf("%s", S);
    int n = strlen(S);
    int can_place_o = 1;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == '#')
        {
            T[i] = '#';
            can_place_o = 1;
        }
        else
        {
            if (can_place_o)
            {
                T[i] = 'o';
                can_place_o = 0;
            }
            else
            {
                T[i] = '.';
            }
        }
    }
    T[n] = '\0';
    printf("%s\n", T);
    return 0;
}