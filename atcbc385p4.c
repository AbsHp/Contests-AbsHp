// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// #define MAX_HOUSES 1000
// #define MAX_MOVES 1000

// int isHouse(int x, int y, int houses[][2], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (houses[i][0] == x && houses[i][1] == y)
//         {
//             return 1;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int N, M;
//     int houses[MAX_HOUSES][2];
//     int Sx, Sy;
//     char directions[MAX_MOVES];
//     int distances[MAX_MOVES];
//     scanf("%d %d %d %d", &N, &M, &Sx, &Sy);
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d %d", &houses[i][0], &houses[i][1]);
//     }
//     for (int i = 0; i < M; i++)
//     {
//         scanf("%c %d", &directions[i], &distances[i]);
//     }
//     int visited[MAX_HOUSES] = {0};
//     int distinctHouses = 0;
//     if (isHouse(Sx, Sy, houses, N))
//     {
//         visited[0] = 1;
//         distinctHouses++;
//     }
//     for (int i = 0; i < M; i++)
//     {
//         char dir = directions[i];
//         int dist = distances[i];
//         for (int step = 1; step <= dist; step++)
//         {
//             if (dir == 'U')
//                 Sy++;
//             else if (dir == 'D')
//                 Sy--;
//             else if (dir == 'L')
//                 Sx--;
//             else if (dir == 'R')
//                 Sx++;
//             for (int j = 0; j < N; j++)
//             {
//                 if (houses[j][0] == Sx && houses[j][1] == Sy && !visited[j])
//                 {
//                     visited[j] = 1;
//                     distinctHouses++;
//                 }
//             }
//         }
//     }
//     printf("%d %d %d", Sx, Sy, distinctHouses);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <stdint.h>

// #define HASH_SIZE 200003
// typedef struct
// {
//     int64_t x, y;
// } Point;

// typedef struct Node
// {
//     Point point;
//     struct Node *next;
// } Node;

// Node *hash_table[HASH_SIZE];

// int hash(int64_t x, int64_t y)
// {
//     return ((x * 31 + y) % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
// }

// void insert(int64_t x, int64_t y)
// {
//     int h = hash(x, y);
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->point.x = x;
//     new_node->point.y = y;
//     new_node->next = hash_table[h];
//     hash_table[h] = new_node;
// }

// bool exists(int64_t x, int64_t y)
// {
//     int h = hash(x, y);
//     Node *node = hash_table[h];
//     while (node)
//     {
//         if (node->point.x == x && node->point.y == y)
//         {
//             return true;
//         }
//         node = node->next;
//     }
//     return false;
// }

// int main()
// {
//     int N, M;
//     int64_t Sx, Sy;
//     scanf("%d %d %lld %lld", &N, &M, &Sx, &Sy);
//     for (int i = 0; i < N; i++)
//     {
//         int64_t x, y;
//         scanf("%lld %lld", &x, &y);
//         insert(x, y);
//     }
//     char direction;
//     int64_t distance, distinct_houses = 0;
//     int64_t x = Sx, y = Sy;
//     Node *visited[HASH_SIZE] = {NULL};
//     for (int i = 0; i < M; i++)
//     {
//         scanf(" %c %lld", &direction, &distance);
//         int64_t nx = x, ny = y;
//         if (direction == 'U')
//             ny += distance;
//         else if (direction == 'D')
//             ny -= distance;
//         else if (direction == 'L')
//             nx -= distance;
//         else if (direction == 'R')
//             nx += distance;
//         if (x == nx)
//         {
//             int64_t step = (y < ny) ? 1 : -1;
//             for (int64_t j = y; j != ny + step; j += step)
//             {
//                 if (exists(x, j) && !exists(x, j))
//                 {
//                     insert(x, j);
//                     distinct_houses++;
//                 }
//             }
//         }
//         else
//         {
//             int64_t step = (x < nx) ? 1 : -1;
//             for (int64_t j = x; j != nx + step; j += step)
//             {
//                 if (exists(j, y) && !exists(j, y))
//                 {
//                     insert(j, y);
//                     distinct_houses++;
//                 }
//             }
//         }
//         x = nx;
//         y = ny;
//     }
//     printf("%lld %lld %lld", x, y, distinct_houses);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <stdint.h>

// #define HASH_SIZE 200003
// typedef struct
// {
//     int64_t x, y;
// } Point;

// typedef struct Node
// {
//     Point point;
//     struct Node *next;
// } Node;

// Node *house_table[HASH_SIZE];
// Node *visited_table[HASH_SIZE];

// int hash(int64_t x, int64_t y)
// {
//     return ((x * 31 + y) % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
// }

// void insert(Node **table, int64_t x, int64_t y)
// {
//     int h = hash(x, y);
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->point.x = x;
//     new_node->point.y = y;
//     new_node->next = table[h];
//     table[h] = new_node;
// }

// bool exists(Node **table, int64_t x, int64_t y)
// {
//     int h = hash(x, y);
//     Node *node = table[h];
//     while (node)
//     {
//         if (node->point.x == x && node->point.y == y)
//         {
//             return true;
//         }
//         node = node->next;
//     }
//     return false;
// }

// int main()
// {
//     int N, M;
//     int64_t Sx, Sy;
//     scanf("%d %d %lld %lld", &N, &M, &Sx, &Sy);
//     for (int i = 0; i < N; i++)
//     {
//         int64_t x, y;
//         scanf("%lld %lld", &x, &y);
//         insert(house_table, x, y);
//     }
//     char direction;
//     int64_t distance, distinct_houses = 0;
//     int64_t x = Sx, y = Sy;
//     for (int i = 0; i < M; i++)
//     {
//         scanf(" %c %lld", &direction, &distance);
//         int64_t nx = x, ny = y;
//         if (direction == 'U')
//             ny += distance;
//         else if (direction == 'D')
//             ny -= distance;
//         else if (direction == 'L')
//             nx -= distance;
//         else if (direction == 'R')
//             nx += distance;

//         if (x == nx)
//         {
//             int64_t step = (y < ny) ? 1 : -1;
//             for (int64_t j = y; j != ny + step; j += step)
//             {
//                 if (exists(house_table, x, j) && !exists(visited_table, x, j))
//                 {
//                     insert(visited_table, x, j);
//                     distinct_houses++;
//                 }
//             }
//         }
//         else
//         {
//             int64_t step = (x < nx) ? 1 : -1;
//             for (int64_t j = x; j != nx + step; j += step)
//             {
//                 if (exists(house_table, j, y) && !exists(visited_table, j, y))
//                 {
//                     insert(visited_table, j, y);
//                     distinct_houses++;
//                 }
//             }
//         }
//         x = nx;
//         y = ny;
//     }
//     printf("%lld %lld %lld\n", x, y, distinct_houses);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <stdint.h>
// #include <set>

// typedef struct
// {
//     int64_t x, y;
// } Point;

// struct PointComparator
// {
//     bool operator()(const Point &a, const Point &b) const
//     {
//         return a.x < b.x || (a.x == b.x && a.y < b.y);
//     }
// };

// int main()
// {
//     int N, M;
//     int64_t Sx, Sy;
//     scanf("%d %d %lld %lld", &N, &M, &Sx, &Sy);

//     // Use a set for storing house locations
//     std::set<Point, PointComparator> houses;
//     for (int i = 0; i < N; i++)
//     {
//         int64_t x, y;
//         scanf("%lld %lld", &x, &y);
//         houses.insert({x, y});
//     }

//     char direction;
//     int64_t distance;
//     int64_t x = Sx, y = Sy;
//     std::set<Point, PointComparator> visited_houses;

//     for (int i = 0; i < M; i++)
//     {
//         scanf(" %c %lld", &direction, &distance);

//         int64_t nx = x, ny = y;
//         if (direction == 'U')
//             ny += distance;
//         else if (direction == 'D')
//             ny -= distance;
//         else if (direction == 'L')
//             nx -= distance;
//         else if (direction == 'R')
//             nx += distance;

//         if (x == nx) // Vertical movement
//         {
//             int64_t step = (y < ny) ? 1 : -1;
//             for (int64_t j = y; j != ny + step; j += step)
//             {
//                 Point p = {x, j};
//                 if (houses.count(p))
//                     visited_houses.insert(p);
//             }
//         }
//         else if (y == ny) // Horizontal movement
//         {
//             int64_t step = (x < nx) ? 1 : -1;
//             for (int64_t j = x; j != nx + step; j += step)
//             {
//                 Point p = {j, y};
//                 if (houses.count(p))
//                     visited_houses.insert(p);
//             }
//         }

//         // Update Santa's current position
//         x = nx;
//         y = ny;
//     }

//     // Output the final position and count of distinct houses visited
//     printf("%lld %lld %d\n", x, y, (int)visited_houses.size());
//     return 0;
// }

// #include <iostream>
// #include <set>
// #include <tuple>

// using namespace std;

// struct Point
// {
//     int64_t x, y;
//     bool operator<(const Point &other) const
//     {
//         return tie(x, y) < tie(other.x, other.y);
//     }
// };

// int main()
// {
//     int N, M;
//     int64_t Sx, Sy;
//     cin >> N >> M >> Sx >> Sy;
//     set<Point> houses;
//     for (int i = 0; i < N; i++)
//     {
//         int64_t x, y;
//         cin >> x >> y;
//         houses.insert({x, y});
//     }
//     char direction;
//     int64_t distance;
//     int64_t x = Sx, y = Sy;
//     set<Point> visited_houses;
//     for (int i = 0; i < M; i++)
//     {
//         cin >> direction >> distance;

//         int64_t nx = x, ny = y;
//         if (direction == 'U')
//             ny += distance;
//         else if (direction == 'D')
//             ny -= distance;
//         else if (direction == 'L')
//             nx -= distance;
//         else if (direction == 'R')
//             nx += distance;
//         if (x == nx)
//         {
//             int64_t step = (y < ny) ? 1 : -1;
//             for (int64_t j = y; j != ny + step; j += step)
//             {
//                 Point p = {x, j};
//                 if (houses.count(p))
//                     visited_houses.insert(p);
//             }
//         }
//         else if (y == ny)
//         {
//             int64_t step = (x < nx) ? 1 : -1;
//             for (int64_t j = x; j != nx + step; j += step)
//             {
//                 Point p = {j, y};
//                 if (houses.count(p))
//                     visited_houses.insert(p);
//             }
//         }
//         x = nx;
//         y = ny;
//     }
//     cout << x << " " << y << " " << visited_houses.size() << endl;
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HASH_SIZE 200003

typedef struct
{
    int64_t x, y;
} Point;

typedef struct Node
{
    Point point;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

int hash(int64_t x, int64_t y)
{
    return ((x * 31 + y) % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

void insert(int64_t x, int64_t y)
{
    int h = hash(x, y);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->point.x = x;
    new_node->point.y = y;
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

int exists(int64_t x, int64_t y)
{
    int h = hash(x, y);
    Node *node = hash_table[h];
    while (node)
    {
        if (node->point.x == x && node->point.y == y)
        {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int main()
{
    int N, M;
    int64_t Sx, Sy;
    scanf("%d %d %lld %lld", &N, &M, &Sx, &Sy);
    for (int i = 0; i < N; i++)
    {
        int64_t x, y;
        scanf("%lld %lld", &x, &y);
        insert(x, y);
    }
    char direction;
    int64_t distance;
    int64_t x = Sx, y = Sy;
    int64_t distinct_houses = 0;
    for (int i = 0; i < M; i++)
    {
        scanf(" %c %lld", &direction, &distance);
        int64_t nx = x, ny = y;
        if (direction == 'U')
            ny += distance;
        else if (direction == 'D')
            ny -= distance;
        else if (direction == 'L')
            nx -= distance;
        else if (direction == 'R')
            nx += distance;
        if (x == nx)
        {
            int64_t step = (y < ny) ? 1 : -1;
            for (int64_t j = y; j != ny + step; j += step)
            {
                if (exists(x, j))
                {
                    distinct_houses++;
                    insert(x, j);
                }
            }
        }
        else if (y == ny)
        {
            int64_t step = (x < nx) ? 1 : -1;
            for (int64_t j = x; j != nx + step; j += step)
            {
                if (exists(j, y))
                {
                    distinct_houses++;
                    insert(j, y);
                }
            }
        }
        x = nx;
        y = ny;
    }
    printf("%lld %lld %lld\n", x, y, distinct_houses);
    return 0;
}

// TLE Goddamit