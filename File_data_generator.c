#include<stdio.h>
#include<stdlib.h>
int main()
{
    // generate random data for dat file with first data as number of data to be taken
    FILE *fp=fopen("8076_3_1_Merge.dat","w");
    printf("Enter number of data to be generated\n");
    int n_076;
    scanf("%d",&n_076);

    fprintf(fp,"%d\n",n_076);
    for(int i=0;i<n_076;i++)
    {
        fprintf(fp,"%d\n",rand()%1000);
    }
    fclose(fp);


return 0;
}