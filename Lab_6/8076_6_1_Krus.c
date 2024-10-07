#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge_8076;

Edge_8076 edges_8076[MAX];
int parent_8076[MAX];
int n, m;

int find_8076(int i) {
    while (parent_8076[i] != i)
        i = parent_8076[i];
    return i;
}

void union1_8076(int i, int j) {
    int a = find_8076(i);
    int b = find_8076(j);
    parent_8076[a] = b;
}

int cmp_8076(const void *a, const void *b) {
    Edge_8076 *edgeA = (Edge_8076 *)a;
    Edge_8076 *edgeB = (Edge_8076 *)b;
    return edgeA->w - edgeB->w;
}

void kruskal_8076() {
    int i, j, ttlCost_8076 = 0;
    Edge_8076 result[MAX];

    for (i = 0; i < n; i++)
        parent_8076[i] = i;

    qsort(edges_8076, m, sizeof(Edge_8076), cmp_8076);

    for (i = 0, j = 0; i < m && j < n - 1; i++) {
        int u = edges_8076[i].u;
        int v = edges_8076[i].v;
        int w = edges_8076[i].w;

        if (find_8076(u) != find_8076(v)) {
            result[j++] = edges_8076[i];
            union1_8076(u, v);
            ttlCost_8076 += w;
        }
    }

    printf("Edge_8076\tCost\n");
    for (i = 0; i < j; i++)
        printf("%d--%d\t%d\n", result[i].u, result[i].v, result[i].w);
    printf("Total Weight of the Spanning Tree: %d\n", ttlCost_8076);
}

int main() {
    int i;

    printf("Enter the number of nodes and edges_8076: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges_8076 (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges_8076[i].u, &edges_8076[i].v, &edges_8076[i].w);
    }

    kruskal_8076();

    return 0;
}