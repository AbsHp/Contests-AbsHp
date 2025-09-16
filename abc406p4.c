#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200005

typedef struct Trash
{
    int x, y;
    struct Trash *next;
} Trash;

Trash *grid[MAX];

int row_count[MAX] = {0};
int col_count[MAX] = {0};
int row_removed[MAX] = {0};
int col_removed[MAX] = {0};

int hash(int x)
{
    return x % MAX;
}

void insert(int x, int y)
{
    int h = hash(x);
    Trash *new_node = malloc(sizeof(Trash));
    new_node->x = x;
    new_node->y = y;
    new_node->next = grid[h];
    grid[h] = new_node;
}

int remove_row(int x, int W)
{
    if (row_removed[x])
        return 0;
    row_removed[x] = 1;
    int h = hash(x);
    Trash *cur = grid[h];
    Trash *prev = NULL;
    int count = 0;
    while (cur)
    {
        if (cur->x == x && !col_removed[cur->y])
        {
            count++;
            col_count[cur->y]--;
        }
        if (cur->x == x)
        {
            if (prev)
                prev->next = cur->next;
            else
                grid[h] = cur->next;
            Trash *temp = cur;
            cur = cur->next;
            free(temp);
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    row_count[x] = 0;
    return count;
}

int remove_col(int y, int H)
{
    if (col_removed[y])
        return 0;
    col_removed[y] = 1;
    int count = 0;
    for (int i = 0; i < MAX; i++)
    {
        Trash *cur = grid[i];
        Trash *prev = NULL;
        while (cur)
        {
            if (cur->y == y && !row_removed[cur->x])
            {
                count++;
                row_count[cur->x]--;
            }
            if (cur->y == y)
            {
                if (prev)
                    prev->next = cur->next;
                else
                    grid[i] = cur->next;
                Trash *temp = cur;
                cur = cur->next;
                free(temp);
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
    }
    col_count[y] = 0;
    return count;
}

int main()
{
    int H, W, N, Q;
    scanf("%d %d %d", &H, &W, &N);
    int x, y;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        row_count[x]++;
        col_count[y]++;
        insert(x, y);
    }
    scanf("%d", &Q);
    int type, idx;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &type, &idx);
        if (type == 1)
        {
            int ans = remove_row(idx, W);
            printf("%d\n", ans);
        }
        else
        {
            int ans = remove_col(idx, H);
            printf("%d\n", ans);
        }
    }
    return 0;
}