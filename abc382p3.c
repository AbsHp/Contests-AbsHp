// #include <stdio.h>

// int main()
// {
//     int N, M;
//     scanf("%d %d", &N, &M);
//     int A[N];
//     int B[M];
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d", &A[i]);
//     }
//     for (int j = 0; j < M; j++)
//     {
//         scanf("%d", &B[j]);
//     }
//     int result[M];
//     for (int j = 0; j < M; j++)
//     {
//         int eaten = 0;
//         for (int i = 0; i < N; i++)
//         {
//             if (B[j] > A[i])
//             {
//                 result[j] = i + 1;
//                 eaten = 1;
//                 break;
//             }
//         }
//         if (!eaten)
//         {
//             result[j] = -1;
//         }
//     }
//     for (int j = 0; j < M; j++)
//     {
//         printf("%d\n", result[j]);
//     }
//     return 0;
// }

#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N];
    int B[M];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int j = 0; j < M; j++)
    {
        scanf("%d", &B[j]);
    }
    int result[M];
    for (int j = 0; j < M; j++)
    {
        int eaten = 0;
        for (int i = 0; i < N; i++)
        {
            if (B[j] >= A[i])
            {
                result[j] = i + 1;
                eaten = 1;
                break;
            }
        }
        if (!eaten)
        {
            result[j] = -1;
        }
    }
    for (int j = 0; j < M; j++)
    {
        printf("%d\n", result[j]);
    }

    return 0;
}

// AtCoder Beginner Contest 382 Problem 3