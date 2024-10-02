#include <stdio.h>

void fnd_scnd_sml_lrg_076(int arr_076[], int n, FILE *outputFile) {
    int sml_076 = arr_076[0];
    int scndSml_076 = arr_076[0];
    int lrg_076 = arr_076[0];
    int scndLrgst_076 = arr_076[0];

    for (int i = 1; i < n; i++) {
        if (arr_076[i] < sml_076) {
            scndSml_076 = sml_076;
            sml_076 = arr_076[i];
        } else if (arr_076[i] < scndSml_076 && arr_076[i] != sml_076) {
            scndSml_076 = arr_076[i];
        }

        if (arr_076[i] > lrg_076) {
            scndLrgst_076 = lrg_076;
            lrg_076 = arr_076[i];
        } else if (arr_076[i] > scndLrgst_076 && arr_076[i] != lrg_076) {
            scndLrgst_076 = arr_076[i];
        }
    }

    fprintf(outputFile, "Second sml_076 element: %d\n", scndSml_076);
    fprintf(outputFile, "Second lrg_076 element: %d\n", scndLrgst_076);
}

void sort_find_8076(int arr_076[], int n, FILE *outputFile)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr_076[i] > arr_076[j])
            {
                temp = arr_076[i];
                arr_076[i] = arr_076[j];
                arr_076[j] = temp;
            }
        }
    }
    

    fprintf(outputFile, "Second sml_076 element: %d\n", arr_076[1]);
    fprintf(outputFile, "Second lrg_076 element: %d\n", arr_076[n-2]);
}
int main() {
    FILE *inputFile = fopen("d:/DAA/Lab_1/8076_1_1_in.dat", "r");
    FILE *outputFile = fopen("output_1_1.dat", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(inputFile, "%d", &n);

    int arr_076[n];
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr_076[i]);
        printf("%d\n", arr_076[i]);
    }

    // fnd_scnd_sml_lrg_076(arr_076, n, outputFile);
    sort_find_8076(arr_076, n, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}