#include <stdio.h>
#include <string.h>


int lcsLength_8076(char *X, char *Y, int m, int n) {
    int L_8076[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L_8076[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L_8076[i][j] = L_8076[i - 1][j - 1] + 1;
            else
                L_8076[i][j] = (L_8076[i - 1][j] > L_8076[i][j - 1]) ? L_8076[i - 1][j] : L_8076[i][j - 1];
        }
    }
    return L_8076[m][n];
}


void findLCS_8076(char *X, char *Y, int m, int n) {
    int L_8076[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L_8076[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L_8076[i][j] = L_8076[i - 1][j - 1] + 1;
            else
                L_8076[i][j] = (L_8076[i - 1][j] > L_8076[i][j - 1]) ? L_8076[i - 1][j] : L_8076[i][j - 1];
        }
    }

    int index = L_8076[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L_8076[i - 1][j] > L_8076[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", L_8076[m][n]);
}

int main() {
    char X[100], Y[100];
    printf("Enter the first string into an array: ");
    scanf("%s", X);
    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    findLCS_8076(X, Y, m, n);

    return 0;
}