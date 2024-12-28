#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canTransform(char *S, char *T, int K)
{
    int lenS = strlen(S);
    int lenT = strlen(T);
    if (K > 1)
    {
        return false;
    }
    if (abs(lenS - lenT) > 1)
    {
        return false;
    }
    int i = 0, j = 0;
    bool operationUsed = false;
    while (i < lenS && j < lenT)
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            if (operationUsed)
            {
                return false;
            }
            operationUsed = true;
            if (lenS < lenT)
            {
                j++;
            }
            else if (lenS > lenT)
            {
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
    if (i < lenS || j < lenT)
    {
        if (operationUsed)
        {
            return false;
        }
        operationUsed = true;
    }
    return true;
}

int main()
{
    int K;
    char S[500001], T[500001];
    scanf("%d", &K);
    scanf("%s", S);
    scanf("%s", T);
    if (canTransform(S, T, K))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}