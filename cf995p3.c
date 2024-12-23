// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_N 300000

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     for (int j = 0; j < t; j++)
//     {
//         int n, m, k;
//         scanf("%d %d %d", &n, &m, &k);
//         int a[m];
//         for (int i = 0; i < m; i++)
//         {
//             scanf("%d", &a[i]);
//         }
//         int q[k];
//         int known[1000001] = {0};
//         for (int i = 0; i < k; i++)
//         {
//             scanf("%d", &q[i]);
//             known[q[i]] = 1;
//         }
//         char result[m + 1];
//         for (int i = 0; i < m; i++)
//         {
//             if (known[a[i]] == 0)
//             {
//                 result[i] = '1';
//             }
//             else
//             {
//                 result[i] = '0';
//             }
//         }
//         result[m] = '\0';
//         printf("%s\n", result);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_N 300000

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         int n, m, k;
//         scanf("%d %d %d", &n, &m, &k);
//         int a[m];
//         for (int i = 0; i < m; i++)
//         {
//             scanf("%d", &a[i]);
//         }
//         int known[1000001] = {0};
//         for (int i = 0; i < k; i++)
//         {
//             int q;
//             scanf("%d", &q);
//             known[q] = 1;
//         }
//         char result[m + 1];
//         for (int i = 0; i < m; i++)
//         {
//             int missing_question = a[i];
//             if (known[missing_question] == 0)
//             {
//                 result[i] = '1';
//             }
//             else
//             {
//                 result[i] = '0';
//             }
//         }
//         result[m] = '\0';
//         printf("%s\n", result);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300000

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int a[m];
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
        }
        int known[1000001] = {0};
        for (int i = 0; i < k; i++)
        {
            int q;
            scanf("%d", &q);
            known[q] = 1;
        }
        char result[m + 1];
        for (int i = 0; i < m; i++)
        {
            int missing_question = a[i];
            int will_pass = 1;
            for (int j = 1; j <= n; j++)
            {
                if (j != missing_question && known[j] == 0)
                {
                    will_pass = 0;
                    break;
                }
            }
            result[i] = (will_pass) ? '1' : '0';
        }
        result[m] = '\0';
        printf("%s\n", result);
    }
    return 0;
}

// TLE :(