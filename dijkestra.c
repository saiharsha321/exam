#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int dist[n];
    int visited[n];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    // Dijkstra algorithm
    for (i = 0; i < n - 1; i++) {

        // Find minimum distance vertex
        int min = INT_MAX, u = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Print result
    printf("\nShortest distances from source:\n");
    for (i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);

    return 0;
}


