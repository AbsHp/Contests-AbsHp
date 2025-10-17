#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005

typedef struct
{
    int l, r;
    int minVal, maxVal;
    int lazy;
} Node;

Node tree[4 * MAXN];
int N, Q;

void build(int id, int l, int r)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].lazy = -1;
    if (l == r)
    {
        tree[id].minVal = tree[id].maxVal = l;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id].minVal = l;
    tree[id].maxVal = r;
}

void push(int id)
{
    if (tree[id].lazy != -1)
    {
        int val = tree[id].lazy;
        int left = 2 * id, right = 2 * id + 1;
        tree[left].minVal = tree[left].maxVal = val;
        tree[right].minVal = tree[right].maxVal = val;
        tree[left].lazy = tree[right].lazy = val;
        tree[id].lazy = -1;
    }
}

int update(int id, int X, int Y)
{
    if (tree[id].minVal > X)
        return 0;
    if (tree[id].maxVal <= X)
    {
        int count = tree[id].r - tree[id].l + 1;
        tree[id].minVal = tree[id].maxVal = Y;
        tree[id].lazy = Y;
        return count;
    }
    push(id);
    int left = update(2 * id, X, Y);
    int right = update(2 * id + 1, X, Y);
    tree[id].minVal = tree[2 * id].minVal < tree[2 * id + 1].minVal ? tree[2 * id].minVal : tree[2 * id + 1].minVal;
    tree[id].maxVal = tree[2 * id].maxVal > tree[2 * id + 1].maxVal ? tree[2 * id].maxVal : tree[2 * id + 1].maxVal;
    return left + right;
}

int main()
{
    scanf("%d %d", &N, &Q);
    build(1, 1, N);
    for (int i = 0; i < Q; ++i)
    {
        int X, Y;
        scanf("%d %d", &X, &Y);
        int result = update(1, X, Y);
        printf("%d\n", result);
    }
    return 0;
}