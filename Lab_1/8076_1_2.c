#include <stdio.h>



int main() {
    
    FILE *inputFile = fopen("d:/DAA/Lab_1/8076_1_1_in.dat", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    int N, i;
    fscanf(inputFile, "%d", &N);
    
     int prefixSum[N];
    
    int arr[N];

    for (i = 0; i < N; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    
    prefixSum[0] = arr[0];
    for (i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

   
    for (i = 0; i < N; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

   
    FILE *outputFile = fopen("8076_1_2_out.dat", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(inputFile);
        return 1;
    }

    for (i = 0; i < N; i++) {
        fprintf(outputFile, "%d ", prefixSum[i]);
        fprintf(outputFile, "\n");
    }
    

    fclose(outputFile);
    fclose(inputFile);

    return 0;
}