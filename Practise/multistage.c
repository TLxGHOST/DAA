#include <stdio.h>

void print_cost_matrix(int cost_ad[13][13])
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            printf("%d ", cost_ad[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int stages = 4;
    int min;
    int n = 13;
    int cost[13], d[13], path[13];
    int cost_adjacency[13][13] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 9, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 2, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Initialize cost array with a large value (infinity)
    for (int i = 0; i < 13; i++)
    {
        cost[i] = 32767;
        d[i] = 0;
    }
    cost[n - 1] = 0; 

    for (int i = n - 2; i >= 0; i--)
    {
        min = 32767;
        for (int k = i + 1; k < n; k++)
        {
            if (cost_adjacency[i][k] != 0 && (cost_adjacency[i][k] + cost[k]) < min)
            {
                min = cost_adjacency[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }
d[n-1]=n-1;
d[0]=0;
cost[0]=0;
    printf("Cost: ");
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", cost[i]);
    }
    printf("\n d :  ");
    for (int i = 0; i < 13; i++)
    {
        printf("%d ", d[i]);
    }

    return 0;
}