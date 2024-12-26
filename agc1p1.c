#include <stdio.h>

void bubblesort(int arr[], int n)
{
    int i, j, temp;
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i += 2)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int N;
    scanf("%d", &N);
    int arr[2 * N];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    int reqsum = sum(arr, n);
    printf("%d", reqsum);
    return 0;
}

// AtCoder Grand Contest 1 P1