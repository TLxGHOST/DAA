// Output: 
//     Edge    Cost 
    // 8--7     1 
    // 7--6     2 
    // 3--9     2 
    // 1--2     4 
    // 3--6     4 `
    // 3--4     7 
    // 1--8     8 
    // 4--5     9 
// Total Weight of the Spanning Tree: 37
#include<stdio.h>
#include<stdlib.h>
struct Edge
{
    int u;
    int v;
    int weight;
};
//Sort the edges in increasing order of their weights
void sort(struct Edge arr[],int n)
{
    struct Edge temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j].weight>arr[j+1].weight)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int Nodes_8076,Edges_8076;
    printf("Enter number of nodes and edges \n");
    scanf("%d %d",&Nodes_8076,&Edges_8076);
    printf("Enter the following Data %d Edges \n",Edges_8076);
    printf("<u> <v> <weight> \n");
    struct Edge arr[Edges_8076];
    for(int i=0;i<Edges_8076;i++)
    {
        scanf("%d %d %d",&(arr[i].u),&(arr[i].v),&(arr[i].weight));
        printf("\n");
    }

    sort(arr,Edges_8076);
    printf("Edges after sorting \n");
    for(int i=0;i<Edges_8076;i++)
    {
        printf("%d %d %d",(arr[i].u),(arr[i].v),(arr[i].weight));
        printf("\n");
    }

    // for(int i=0;i<Edges_8076;i++)
    // {
    //     printf("%d %d %d",(arr[i].u),(arr[i].v),(arr[i].weight));
    //     printf("\n");
    // }
    
return 0;
}