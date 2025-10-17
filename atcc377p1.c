#include <stdio.h>
#include <string.h>

int main()
{
    char a, b, c;
    scanf("%c%c%c", &a, &b, &c);
    if ((a == 'A' && b == 'B' && c == 'C') || (a == 'B' && b == 'A' && c == 'C') || (a == 'A' && b == 'C' && c == 'B') || (a == 'C' && b == 'A' && c == 'B') || (a == 'C' && b == 'B' && c == 'A') || (a == 'B' && b == 'C' && c == 'A'))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}