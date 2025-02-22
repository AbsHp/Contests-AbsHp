#include <stdio.h>
#include <string.h>

#define MAX_LEN 300005

int is_colorful_bracket_sequence(const char *S)
{
    char stack[MAX_LEN];
    int top = -1;
    for (int i = 0; S[i] != '\0'; i++)
    {
        if (S[i] == '(' || S[i] == '[' || S[i] == '<')
        {
            stack[++top] = S[i];
        }
        else
        {
            if (top == -1)
                return 0;
            char topChar = stack[top--];
            if ((S[i] == ')' && topChar != '(') ||
                (S[i] == ']' && topChar != '[') ||
                (S[i] == '>' && topChar != '<'))
            {
                return 0;
            }
        }
    }
    return top == -1;
}

int main()
{
    char S[MAX_LEN];
    scanf("%s", S);
    if (is_colorful_bracket_sequence(S))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}