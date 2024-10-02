#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];
int n, m;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int cmp(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->w - edgeB->w;
}

void kruskal() {
    int i, j, totalCost = 0;
    Edge result[MAX];

    for (i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, m, sizeof(Edge), cmp);

    for (i = 0, j = 0; i < m && j < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            result[j++] = edges[i];
            union1(u, v);
            totalCost += w;
        }
    }

    printf("Edge\tCost\n");
    for (i = 0; i < j; i++)
        printf("%d--%d\t%d\n", result[i].u, result[i].v, result[i].w);
    printf("Total Weight of the Spanning Tree: %d\n", totalCost);
}

int main() {
    int i;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal();

    return 0;
}