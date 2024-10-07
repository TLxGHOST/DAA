#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void readGraph_8076(int n, int graph[n][n], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
}

int minkey_8076(int key[], int mstSet[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST_8076(int parent[], int n, int graph[n][n]) {
    int totalWeight = 0;
    int mst[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mst[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        mst[parent[i]][i] = graph[i][parent[i]];
        mst[i][parent[i]] = graph[i][parent[i]];
        totalWeight += graph[i][parent[i]];
    }
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

void primMST(int n, int graph[n][n], int startNode) {
    int parent[n];
    int key[n];
    int mstSet[n];
    for (int i = 0; i < n; i++) {
        key[i] = INF, mstSet[i] = 0;
    }
    key[startNode] = 0;
    parent[startNode] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minkey_8076(key, mstSet, n);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    printMST_8076(parent, n, graph);
}

int main() {
    int n, startNode;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    readGraph_8076(n, graph, "inUnAdjMat_8076.dat");
    printf("Enter the Starting Node  : ");
    scanf("%d", &startNode);
    primMST(n, graph, startNode);
    return 0;
}