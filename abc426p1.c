#include <stdio.h>
#include <string.h>

int version_to_number(const char *version)
{
    if (strcmp(version, "Ocelot") == 0)
        return 0;
    if (strcmp(version, "Serval") == 0)
        return 1;
    if (strcmp(version, "Lynx") == 0)
        return 2;
    return -1;
}

int main()
{
    char X[20], Y[20];
    scanf("%s %s", X, Y);
    int x_version = version_to_number(X);
    int y_version = version_to_number(Y);
    if (x_version == -1 || y_version == -1)
    {
        printf("No\n");
    }
    else if (x_version >= y_version)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}