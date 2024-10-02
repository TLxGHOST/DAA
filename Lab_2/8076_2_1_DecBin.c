//2.1 Aim of the program: Write a program in C to convert the first „n‟ decimal numbers of a disc 
// file to binary using recursion. Store the binary value in a separate disc file.  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void decToBin(int n_076,FILE *fp)
{
    // printf("Function runnig too");
    if(n_076==0)
    {
        return;
    }
    decToBin(n_076/2,fp);
    fprintf(fp,"%d",n_076%2);
}

//main function with parameters 
int main(int argc, char * argv[])
{
    //File pointer for input and output file
    // FILE *fpIn=fopen("8076_2_1_inDec.dat","r");
    // FILE *fpOut=fopen("8076_2_1_outBin.dat","w");
    
    FILE *fpIn=fopen(argv[2],"r");
    FILE *fpOut=fopen(argv[3],"w");
    // printf("PArt working fine");
  
    if(fpIn==NULL || fpOut==NULL)
    {
        printf("part whn no file is executed\n");
        exit(0);
    }

    int n_076=atoi(argv[1]);
    int temp;
    fscanf(fpIn,"%d",&temp);
    fprintf(fpOut,"There are %d values in Input file out of wwhich %d are being converted ",temp,n_076);
    for(int i=0;i<n_076;i++)
    {
        int num_076;
        fscanf(fpIn,"%d",&num_076);
        fprintf(fpOut,"Decimal %d : ",num_076);
        decToBin(num_076,fpOut);
        fprintf(fpOut," Binary \n");
    }


    return 0;
}

