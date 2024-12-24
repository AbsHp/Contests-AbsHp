#include <stdio.h>

int maxBuildings(int heights[], int n)
{
    int maxCount = 1;
    for (int h = 0; h < n; h++)
    {
        for (int interval = 1; interval < n; interval++)
        {
            int count = 1;
            int prevIndex = h;
            for (int i = h + interval; i < n; i += interval)
            {
                if (heights[i] == heights[prevIndex])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
            }
        }
    }
    return maxCount;
}

int main()
{
    int n;
    printf("Enter the number of buildings: ");
    scanf("%d", &n);
    int heights[n];
    printf("Enter the heights of the buildings: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heights[i]);
    }
    int result = maxBuildings(heights, n);
    printf("%d\n", result);
    return 0;
}

// AtCoder Beginner Contest 385 P3