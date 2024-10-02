
#include<stdio.h>
#include<stdlib.h>

struct ITEM_8076
{
    int item_id_8076;
    float item_profit_8076;
    float item_weight_8076;
    float profit_weight_ratio_8076;
};

void swap_8076(struct ITEM_8076 *a, struct ITEM_8076 *b)
{
    struct ITEM_8076 temp = *a;
    *a = *b;
    *b = temp;
}

int partition_8076(struct ITEM_8076 arr[], int low, int high)
{
    float pivot = arr[high].profit_weight_ratio_8076;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].profit_weight_ratio_8076 > pivot)
        {
            i++;
            swap_8076(&arr[i], &arr[j]);
        }
    }
    swap_8076(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort_8076(struct ITEM_8076 arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_8076(arr, low, high);
        quickSort_8076(arr, low, pi - 1);
        quickSort_8076(arr, pi + 1, high);
    }
}

void fractionalKnapsack_8076(struct ITEM_8076 items[], int n, float capacity)
{
    float current_weight_8076 = 0;
    float current_profit_8076 = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_weight_8076 + items[i].item_weight_8076 <= capacity)
        {
            current_weight_8076 += items[i].item_weight_8076;
            current_profit_8076 += items[i].item_profit_8076;
            printf("Item No %d: %f %f %f\n", items[i].item_id_8076, items[i].item_profit_8076, items[i].item_weight_8076, 1.0);
        }
        else
        {
            float remaining_weight = capacity - current_weight_8076;
            current_profit_8076 += items[i].profit_weight_ratio_8076 * remaining_weight;
            printf("Item No %d: %f %f %f\n", items[i].item_id_8076, items[i].item_profit_8076, items[i].item_weight_8076, remaining_weight / items[i].item_weight_8076);
            break;
        }
    }

    printf("Maximum profit: %f\n", current_profit_8076);
}

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct ITEM_8076 items[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Item ID %d: ", i + 1);
        scanf("%d", &items[i].item_id_8076);
        printf("Enter the profit %d : ",items[i].item_id_8076);
        scanf("%f", &items[i].item_profit_8076);
        printf("Enter weight of item %d: ", items[i].item_id_8076);
        scanf("%f",&items[i].item_weight_8076);
        items[i].profit_weight_ratio_8076 = items[i].item_profit_8076 / items[i].item_weight_8076;
    }
    quickSort_8076(items, 0, n - 1);
    float capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);
    fractionalKnapsack_8076(items, n, capacity);
    return 0;
}


