

#include <stdio.h>
#include <stdlib.h>

void countDuplicates(int arr[], int N)
{
    int i, j, count = 0;
    int dup[N];
    int flag = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = 0; k < N; k++)
                {
                    if (arr[i] == dup[k])
                    {
                        flag = 1;
                        break;
                    }
                }
            
            if (!flag)
            {
                count++;
                dup[i] = arr[i];
                break;
            }
        }
    }
}
printf("Total number of duplicate elements: %d\n", count);
}

void mostRepeatingElement(int arr[], int N)
{
    int i, j, maxCount = 0, maxElement = arr[0];
    for (i = 0; i < N; i++)
    {
        int count = 1;
        for (j = i + 1; j < N; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    printf("Most repeating element: %d\n", maxElement);
}

int main()
{
    FILE *inputFile = fopen("d:/DAA/Lab_1/8076_1_1_in.dat", "r");
    if (inputFile == NULL)
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    int N, i;
    fscanf(inputFile, "%d", &N);

    int arr[N];

    for (i = 0; i < N; i++)
    {
        fscanf(inputFile, "%d", &arr[i]);
    }

    countDuplicates(arr, N);
    mostRepeatingElement(arr, N);

    fclose(inputFile);

    return 0;
}