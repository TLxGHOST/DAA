#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX], dist[MAX], prev[MAX], visited[MAX];
int n;

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = INF, u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

void printPath(int j) {
    if (prev[j] == -1) return;
    printPath(prev[j]);
    printf("->%d", j + 1);
}

int main() {
    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    int src;
    printf("Enter the Number of Vertices: %d\n", n);
    int v;
    scanf("%d", &v);
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--;

    dijkstra(src);

    printf("Source Destination Cost Path\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d ", src + 1, i + 1, dist[i]);
        if (dist[i] == INF) {
            printf("-\n");
        } else {
            printf("%d", src + 1);
            printPath(i);
            printf("\n");
        }
    }

    return 0;
}