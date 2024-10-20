#include <stdio.h>
#include <limits.h>

void printOptimalParens_8076(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens_8076(s, i, s[i][j]);
        printOptimalParens_8076(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder_8076(int p[], int n) {
    int m[100][100];
    int s[100][100];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i <= j) {
                printf("%d\t", m[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i <= j) {
                printf("%d\t", s[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParens_8076(s, 1, n - 1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n - 1]);
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[100];
    for (int i = 0; i < n; i++) {
        int row, col;
        printf("Enter row and col size of A%d: \n", i + 1);
        scanf("%d %d", &row, &col);
        if (i == 0) {
            p[i] = row;
        }
        p[i + 1] = col;
    }

    matrixChainOrder_8076(p, n + 1);

    return 0;
}