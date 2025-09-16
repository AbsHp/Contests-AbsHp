#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define INF 1000000000

typedef struct
{
    int count;
    int box;
} Box;

void swap(Box *a, Box *b)
{
    Box temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(Box heap[], int index)
{
    while (index > 1 && (heap[index].count < heap[index / 2].count ||
                         (heap[index].count == heap[index / 2].count && heap[index].box < heap[index / 2].box)))
    {
        swap(&heap[index], &heap[index / 2]);
        index /= 2;
    }
}

void heapify_down(Box heap[], int size, int index)
{
    int smallest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    if (left <= size && (heap[left].count < heap[smallest].count ||
                         (heap[left].count == heap[smallest].count && heap[left].box < heap[smallest].box)))
    {
        smallest = left;
    }
    if (right <= size && (heap[right].count < heap[smallest].count ||
                          (heap[right].count == heap[smallest].count && heap[right].box < heap[smallest].box)))
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(&heap[smallest], &heap[index]);
        heapify_down(heap, size, smallest);
    }
}

void push(Box heap[], int *size, Box value)
{
    heap[++(*size)] = value;
    heapify_up(heap, *size);
}

Box pop(Box heap[], int *size)
{
    Box top = heap[1];
    heap[1] = heap[*size];
    (*size)--;
    heapify_down(heap, *size, 1);
    return top;
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int X[MAXN];
    int count[MAXN] = {0};
    Box heap[2 * MAXN];
    int heap_size = 0;
    for (int i = 1; i <= N; i++)
    {
        push(heap, &heap_size, (Box){0, i});
    }
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &X[i]);
    }
    for (int i = 0; i < Q; i++)
    {
        if (X[i] >= 1)
        {
            int box = X[i];
            count[box]++;
            push(heap, &heap_size, (Box){count[box], box});
            printf("%d ", box);
        }
        else
        {
            while (1)
            {
                Box top = pop(heap, &heap_size);
                if (top.count == count[top.box])
                {
                    count[top.box]++;
                    push(heap, &heap_size, (Box){count[top.box], top.box});
                    printf("%d ", top.box);
                    break;
                }
            }
        }
    }
    return 0;
}