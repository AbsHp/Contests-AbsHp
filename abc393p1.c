#include <stdio.h>
#include <string.h>

int main()
{
    char S1[5];
    char S2[5];
    scanf("%s %s", S1, S2);
    if (strcmp(S1, "sick") == 0 && strcmp(S2, "fine") == 0)
    {
        printf("2");
    }
    else if (strcmp(S1, "fine") == 0 && strcmp(S2, "sick") == 0)
    {
        printf("3");
    }
    else if (strcmp(S1, "sick") == 0 && strcmp(S2, "sick") == 0)
    {
        printf("1");
    }
    else if (strcmp(S1, "fine") == 0 && strcmp(S2, "fine") == 0)
    {
        printf("4");
    }
    return 0;
}