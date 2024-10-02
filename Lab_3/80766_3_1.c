
#include <stdio.h>
#include <stdlib.h>

#define Max 1000
void merge(int arr_076[], int l, int m, int r, int *comparisons)

 {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr_076[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr_076[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr_076[k] = L[i];
            i++;
        }
        else {
            arr_076[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr_076[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr_076[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr_076[], int l, int r, int *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr_076, l, m, comparisons);
        merge_sort(arr_076, m + 1, r, comparisons);
        merge(arr_076, l, m, r, comparisons);
    }
}

 

int main()
{

    int choice_076;
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice_076);
   
       

        int arr_076[Max];
 FILE *inputFile_076;
 FILE *outputFile;
 int comparisons;

 int N_076;
    switch (choice_076)
    {
    case 1:
        
        inputFile_076 = fopen("inAsce.dat", "r");
        if (inputFile_076 == NULL)
        {
            printf("Failed to open the input file.\n");
            return 1;
        }

        int N_076, i;
        fscanf(inputFile_076, "%d", &N_076);
        
        

        for (i = 0; i < N_076; i++)
        {
            fscanf(inputFile_076, "%d", &arr_076[i]);
        }

        comparisons = 0;
        merge_sort(arr_076, 0, N_076 - 1, &comparisons);

        outputFile = fopen("outMergeAsce.dat", "w");
        if (outputFile == NULL)
        {
            printf("Failed to open the output file.\n");
            fclose(inputFile_076);
            return 1;
        }

        for (i = 0; i < N_076; i++)
        {
            fprintf(outputFile, "%d ", arr_076[i]);
            fprintf(outputFile, "\n");
        }
        fprintf(outputFile,"There will be %d no of comparisions ",comparisons);
        fclose(outputFile);
        fclose(inputFile_076);

        break;

    case 2:
        
        inputFile_076 = fopen("inDesc.dat", "r");
        if (inputFile_076 == NULL)
        {
            printf("Failed to open the input file.\n");
            return 1;
        }

      
        fscanf(inputFile_076, "%d", &N_076);

        

        for (i = 0; i < N_076; i++)
        {
            fscanf(inputFile_076, "%d", &arr_076[i]);
        }

        comparisons = 0;
        merge_sort(arr_076, 0, N_076 - 1, &comparisons);

        outputFile = fopen("outMergeDesc.dat", "w");
        if (outputFile == NULL)
        {
            printf("Failed to open the output file.\n");
            fclose(inputFile_076);
            return 1;

            for (i = 0; i < N_076; i++)
            {
                fprintf(outputFile, "%d ", arr_076[i]);
                fprintf(outputFile, "\n");
            }
            fprintf(outputFile,"There will be %d no of comparisions ",comparisons);
            fclose(outputFile);
            fclose(inputFile_076);

            break;

        case 3:
             inputFile_076 = fopen("8076_3_1_RNDM.dat", "r");
            if (inputFile_076 == NULL)
            {
                printf("Failed to open the input file.\n");
                return 1;
            }

            
            fscanf(inputFile_076, "%d", &N_076);

           
            for (i = 0; i < N_076; i++)
            {
                fscanf(inputFile_076, "%d", &arr_076[i]);
            }

            comparisons = 0;
            merge_sort(arr_076, 0, N_076 - 1, &comparisons);

            outputFile = fopen("outMergeRand.dat", "w");
            if (outputFile == NULL)
            {
                printf("Failed to open the output file.\n");
                fclose(inputFile_076);
                return 1;
            }

            for (i = 0; i < N_076; i++)
            {
                fprintf(outputFile, "%d ", arr_076[i]);
                fprintf(outputFile, "\n");
            }
            fprintf(outputFile,"There will be %d no of comparisions ",comparisons);

            fclose(outputFile);
            fclose(inputFile_076);

            break;

        case 4:
           
            return 0;
            break;

        default:
            printf("Invalid choice_076\n");
            break;
        }

        return 0;
    }
}