#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph_8076[MAX][MAX], dist_8076[MAX], prev_8076[MAX],  visited_8076[MAX];
int n;

void dijkstra_8076(int src) {
    for (int i = 0; i < n; i++) {
        dist_8076[i] = INF;
        prev_8076[i] = -1;
         visited_8076[i] = 0;
    }
    dist_8076[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = INF, u = -1;
        for (int j = 0; j < n; j++) {
            if (! visited_8076[j] && dist_8076[j] < min) {
                min = dist_8076[j];
                u = j;
            }
        }

        if (u == -1) break;
         visited_8076[u] = 1;

        for (int v = 0; v < n; v++) {
            if (! visited_8076[v] && graph_8076[u][v] && dist_8076[u] != INF && dist_8076[u] + graph_8076[u][v] < dist_8076[v]) {
                dist_8076[v] = dist_8076[u] + graph_8076[u][v];
                prev_8076[v] = u;
            }
        }
    }
}

void printPath_8076(int j) {
    if (prev_8076[j] == -1) return;
    printPath_8076(prev_8076[j]);
    printf("->%d", j + 1);
}

int main() {
    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }
 printf("Enter the Number of Vertices: \n");
    scanf("%d", &n);
    // fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph_8076[i][j]);
        }
    }
    fclose(file);

    int src;
    // int v;
   
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--;

    dijkstra_8076(src);

    printf("Source Destination Cost Path\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d ", src + 1, i + 1, dist_8076[i]);
        if (dist_8076[i] == INF) {
            printf("-\n");
        } else {
            printf("%d", src + 1);
            printPath_8076(i);
            printf("\n");
        }
    }

    return 0;
}