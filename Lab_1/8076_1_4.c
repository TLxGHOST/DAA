

#include <stdio.h>
#include <stdlib.h>

void Rotate_right_8076(int arr[], int n, int p)
{
   int temp=arr[p-1];
    for(int i=p-1;i>0;i--)
    {
         arr[i]=arr[i-1];
    }
    arr[0]=temp;
}

int main()
{
    int n;
       
    FILE *inputFile = fopen("./8076_1_1_in.dat", "r");
    if (inputFile == NULL)
    {
        printf("Failed to open the input file.\n");
        return 0;
    }
    fscanf(inputFile, "%d", &n);
    int mtrx_8076[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(inputFile, "%d", &mtrx_8076[i][j]);
        }
    }
    fclose(inputFile);
    Rotate_right_8076(mtrx_8076[0], n, n);
    FILE *outputFile = fopen("8076_1_4_out.dat", "w");
    printf("enter value of p1");
    int p;
    scanf("%d",&p);
    Rotate_right_8076(mtrx_8076[0], n, p);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(outputFile, "%d ", mtrx_8076[i][j]);
        }
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);
    
   return 0; 

}