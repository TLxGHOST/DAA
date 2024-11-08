#include <stdio.h>
#define MAX 100


void Sort_quick(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        Sort_quick(arr, l, p - 1);
        Sort_quick(arr, p + 1, h);
    }
}



int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = temp;
    return (i + 1);

}

int main() {
    printf("Enter the number of elements in array \n");
    int n;
    int arr[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data\n");
        int temp;
        scanf("%d",&temp);

        arr[i]=temp;
    }
    Sort_quick(arr,0,n-1);
    printf("Sorted Array \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
