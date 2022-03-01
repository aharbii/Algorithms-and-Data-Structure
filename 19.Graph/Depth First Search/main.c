#include <stdio.h>
#include <stdlib.h>

void depth_first_search(int u, int *visited, int n, int A[][7])
{
    if (visited[u] == 0)
    {
        printf("%d ", u);
        visited[u] = 1;
        for (int v = 1; v < n; v++)
        {
            if (A[u][v] && !visited[v])
            {
                depth_first_search(v, visited, n, A);
            }
        }
    }
}

int main()
{
    int A[][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    int *visited = (int *)calloc(7, sizeof(int));
    depth_first_search(4, visited, 7, A);
    printf("\n");
    return 0;
}