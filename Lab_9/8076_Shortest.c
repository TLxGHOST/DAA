#include <stdio.h>
#include <stdlib.h>
#define INF 99999

void printMatrix_8076(int **matrix_8076, int n_8076);
void floydWarshall_8076(int **graph_8076, int n_8076, int **dist_8076, int **path_8076);
void findPath_8076(int **path_8076, int src_8076, int dest_8076);

int main() {
    int n_8076, src_8076, dest_8076;
    FILE *file_8076 = fopen("inDiAdjMat2.dat", "r");
    if (!file_8076) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n_8076);

    int **graph_8076 = (int **)malloc(n_8076 * sizeof(int *));
    int **dist_8076 = (int **)malloc(n_8076 * sizeof(int *));
    int **path_8076 = (int **)malloc(n_8076 * sizeof(int *));
    for (int i_8076 = 0; i_8076 < n_8076; i_8076++) {
        graph_8076[i_8076] = (int *)malloc(n_8076 * sizeof(int));
        dist_8076[i_8076] = (int *)malloc(n_8076 * sizeof(int));
        path_8076[i_8076] = (int *)malloc(n_8076 * sizeof(int));
        for (int j_8076 = 0; j_8076 < n_8076; j_8076++) {
            fscanf(file_8076, "%d", &graph_8076[i_8076][j_8076]);
            if (i_8076 == j_8076)
                path_8076[i_8076][j_8076] = i_8076;
            else if (graph_8076[i_8076][j_8076] != 0 && graph_8076[i_8076][j_8076] != INF)
                path_8076[i_8076][j_8076] = i_8076;
            else
                path_8076[i_8076][j_8076] = -1;
            if (graph_8076[i_8076][j_8076] == 0 && i_8076 != j_8076)
                dist_8076[i_8076][j_8076] = INF;
            else
                dist_8076[i_8076][j_8076] = graph_8076[i_8076][j_8076];
        }
    }
    fclose(file_8076);

    floydWarshall_8076(graph_8076, n_8076, dist_8076, path_8076);

    printf("Shortest Path Weight Matrix:\n");
    printMatrix_8076(dist_8076, n_8076);

    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &src_8076, &dest_8076);
    src_8076--;
    dest_8076--;

    if (dist_8076[src_8076][dest_8076] == INF) {
        printf("No path exists from vertex %d to vertex %d.\n", src_8076 + 1, dest_8076 + 1);
    } else {
        printf("Shortest Path from vertex %d to vertex %d: ", src_8076 + 1, dest_8076 + 1);
        findPath_8076(path_8076, src_8076, dest_8076);
        printf("\nPath weight: %d\n", dist_8076[src_8076][dest_8076]);
    }

    for (int i_8076 = 0; i_8076 < n_8076; i_8076++) {
        free(graph_8076[i_8076]);
        free(dist_8076[i_8076]);
        free(path_8076[i_8076]);
    }
    free(graph_8076);
    free(dist_8076);
    free(path_8076);

    return 0;
}

void printMatrix_8076(int **matrix_8076, int n_8076) {
    for (int i_8076 = 0; i_8076 < n_8076; i_8076++) {
        for (int j_8076 = 0; j_8076 < n_8076; j_8076++) {
            if (matrix_8076[i_8076][j_8076] == INF)
                printf("INF ");
            else
                printf("%d ", matrix_8076[i_8076][j_8076]);
        }
        printf("\n");
    }
}

void floydWarshall_8076(int **graph_8076, int n_8076, int **dist_8076, int **path_8076) {
    for (int k_8076 = 0; k_8076 < n_8076; k_8076++) {
        for (int i_8076 = 0; i_8076 < n_8076; i_8076++) {
            for (int j_8076 = 0; j_8076 < n_8076; j_8076++) {
                if (dist_8076[i_8076][k_8076] != INF && dist_8076[k_8076][j_8076] != INF && 
                    dist_8076[i_8076][j_8076] > dist_8076[i_8076][k_8076] + dist_8076[k_8076][j_8076]) {
                    dist_8076[i_8076][j_8076] = dist_8076[i_8076][k_8076] + dist_8076[k_8076][j_8076];
                    path_8076[i_8076][j_8076] = path_8076[k_8076][j_8076];
                }
            }
        }
    }
}

void findPath_8076(int **path_8076, int src_8076, int dest_8076) {
    if (path_8076[src_8076][dest_8076] == src_8076) {
        printf("%d --> %d", src_8076 + 1, dest_8076 + 1);
    } else {
        findPath_8076(path_8076, src_8076, path_8076[src_8076][dest_8076]);
        printf(" --> %d", dest_8076 + 1);
    }
}
