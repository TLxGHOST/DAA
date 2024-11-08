#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 500

void quick_sort(int arr[], int low, int high, int *comparisons)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        int j;
        for (j = low; j < high; j++)
        {
            (*comparisons)++;
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        quick_sort(arr, low, i, comparisons);
        quick_sort(arr, i + 2, high, comparisons);
    }
}


int main()
{

    int choice;
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    int prefixSum[Max];

    int arr[Max];
    FILE *inputFile;
    FILE *outputFile;
    int comparisons;

    int N;
    switch (choice)
    {
    case 1:

        inputFile = fopen("inAsce.dat", "r");
        if (inputFile == NULL)
        {
            printf("Failed to open the input file.\n");
            return 1;
        }

        int N, i;
        fscanf(inputFile, "%d", &N);

        for (i = 0; i < N; i++)
        {
            fscanf(inputFile, "%d", &arr[i]);
        }

        comparisons = 0;
        quick_sort(arr, 0, N - 1, &comparisons);

        outputFile = fopen("outQuickAsce.dat", "w");
        if (outputFile == NULL)
        {
            printf("Failed to open the output file.\n");
            return 1;
        }

        for (i = 0; i < N; i++)
        {
            fprintf(outputFile, "%d\n", arr[i]);
        }

        printf("Before Sorting: Content of the input file\n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("After Sorting: Content of the output file\n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == N - 1)
        {
            printf("Scenario: Best-case\n");
        }
        else if (comparisons == (N * (N - 1)) / 2)
        {
            printf("Scenario: Worst-case\n");
        }
        else
        {
            printf("Scenario: Average-case\n");
        }

        break;
    case 2:

        inputFile = fopen("inDesc.dat", "r");
        if (inputFile == NULL)
        {
            printf("Failed to open the input file.\n");
            return 1;
        }

        fscanf(inputFile, "%d", &N);

        for (i = 0; i < N; i++)
        {
            fscanf(inputFile, "%d", &arr[i]);
        }

        comparisons = 0;
        quick_sort(arr, 0, N - 1, &comparisons);

        outputFile = fopen("outQuickDesc.dat", "w");
        if (outputFile == NULL)
        {
            printf("Failed to open the output file.\n");
            return 1;
        }

        for (i = 0; i < N; i++)
        {
            fprintf(outputFile, "%d\n", arr[i]);
        }

        printf("Before Sorting: Content of the input file\n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        printf("After Sorting: Content of the output file\n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == N - 1)
        {
            printf("Scenario: Best-case\n");
        }
        else if (comparisons == (N * (N - 1)) / 2)
        {
            printf("Scenario: Worst-case\n");
        }
        else
        {
            printf("Scenario: Average-case\n");
        }

        break;
    case 3:

        inputFile = fopen("8076_3_1_RNDM.dat", "r");
        if (inputFile == NULL)
        {
            printf("Failed to open the input file.\n");
            return 1;
        }

        fscanf(inputFile, "%d", &N);

        for (i = 0; i < N; i++)
        {
            fscanf(inputFile, "%d", &arr[i]);
        }

        comparisons = 0;
        quick_sort(arr, 0, N - 1, &comparisons);

        outputFile = fopen("outQuickRand.dat", "w");
        if (outputFile == NULL)
        {
            printf("Failed to open the output file.\n");
            return 1;
        }

        for (i = 0; i < N; i++)
        {
            fprintf(outputFile, "%d\n", arr[i]);
        }

        printf("Before Sorting: Content of the input file\n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("After Sorting: Content of the output file\n");
        for (i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == N - 1)
        {
            printf("Scenario: Best-case\n");
        }
        else if (comparisons == (N * (N - 1)) / 2)
        {
            printf("Scenario: Worst-case\n");
        }
        else
        {
            printf("Scenario: Average-case\n");
        }

        break;

    case 4:
        return 0;
    default:
        printf("Invalid choice\n");
    }

    fclose(outputFile);
    fclose(inputFile);

    return 0;
}

