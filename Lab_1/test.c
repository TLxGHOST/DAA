#include <stdio.h>

// Function to swap/exchange the numbers p & q
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate the first p2 elements of the array to the right by 1 position
void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 <= 1) return; // No need to rotate if p2 is 1 or less

    int last = p1[p2 - 1]; // Store the last element
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
    p1[0] = last; // Place the last element at the first position
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p2 = 3; // Number of elements to rotate

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ROTATE_RIGHT(arr, p2);

    printf("Array after rotating first %d elements to the right: ", p2);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}