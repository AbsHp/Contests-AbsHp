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
    scanf("%d %d", &N, &M); // Input number of people and pieces of sushi

    int A[N]; // Gourmet levels of people
    int B[M]; // Deliciousness of sushi

    // Input gourmet levels
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    // Input deliciousness of sushi
    for (int j = 0; j < M; j++)
    {
        scanf("%d", &B[j]);
    }

    // Array to store the result for each sushi
    int result[M];

    // Iterate over each sushi
    for (int j = 0; j < M; j++)
    {
        int eaten = 0; // Flag to check if the sushi is eaten
        for (int i = 0; i < N; i++) // Check each person in order
        {
            if (B[j] >= A[i]) // Sushi deliciousness >= person's gourmet level
            {
                result[j] = i + 1; // Person i eats the sushi
                eaten = 1;
                break; // Sushi is eaten, move to the next sushi
            }
        }
        if (!eaten) // If nobody eats the sushi
        {
            result[j] = -1;
        }
    }

    // Print the results
    for (int j = 0; j < M; j++)
    {
        printf("%d\n", result[j]);
    }

    return 0;
}

// AtCoder Beginner Contest 382 Problem 3