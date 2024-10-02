#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id_076;
    char *name_076;
    int age_076;
    int height_076;
    int weight_076;
};

void minHeapify_076(struct person *people_076, int n_076, int i_076);
void maxHeapify_076(struct person *people_076, int n_076, int i_076);

void swap_076(struct person *a_076, struct person *b_076) {
    struct person temp_076 = *a_076;
    *a_076 = *b_076;
    *b_076 = temp_076;
}
void readData_076(struct person **people_076, int *n_076) {
    printf("Enter the number of people: ");
    scanf("%d", n_076);

    *people_076 = (struct person *)malloc(*n_076 * sizeof(struct person));

    for (int i_076 = 0; i_076 < *n_076; i_076++) {
        (*people_076)[i_076].name_076 = (char *)malloc(50 * sizeof(char));

        printf("Enter details for person %d:\n", i_076 + 1);
        printf("ID: ");
        scanf("%d", &(*people_076)[i_076].id_076);
        printf("Name: ");
        scanf("%s", (*people_076)[i_076].name_076);
        printf("Age: ");
        scanf("%d", &(*people_076)[i_076].age_076);
        printf("Height: ");
        scanf("%d", &(*people_076)[i_076].height_076);
        printf("Weight: ");
        scanf("%d", &(*people_076)[i_076].weight_076);
    }
}

void createMinHeap_076(struct person *people_076, int n_076) {
    for (int i_076 = n_076 / 2 - 1; i_076 >= 0; i_076--) {
        minHeapify_076(people_076, n_076, i_076);
    }
}

void createMaxHeap_076(struct person *people_076, int n_076) {
    for (int i_076 = n_076 / 2 - 1; i_076 >= 0; i_076--) {
        maxHeapify_076(people_076, n_076, i_076);
    }
}

void displayWeightOfYoungest_076(struct person *people_076, int n_076) {
    if (n_076 == 0) {
        printf("No people in the list.\n");
        return;
    }
    createMinHeap_076(people_076, n_076);
    printf("Weight of the youngest person: %d\n", people_076[0].weight_076);
}

void insertPersonMinHeap_076(struct person **people_076, int *n_076) {
    *people_076 = (struct person *)realloc(*people_076, (*n_076 + 1) * sizeof(struct person));
    (*people_076)[*n_076].name_076 = (char *)malloc(50 * sizeof(char));

    printf("Enter details for the new person:\n");
    printf("ID: ");
    scanf("%d", &(*people_076)[*n_076].id_076);
    printf("Name: ");
    scanf("%s", (*people_076)[*n_076].name_076);
    printf("Age: ");
    scanf("%d", &(*people_076)[*n_076].age_076);
    printf("Height: ");
    scanf("%d", &(*people_076)[*n_076].height_076);
    printf("Weight: ");
    scanf("%d", &(*people_076)[*n_076].weight_076);

    (*n_076)++;
    createMinHeap_076(*people_076, *n_076);
}

void deleteOldestPerson_076(struct person **people_076, int *n_076) {
    if (*n_076 == 0) {
        printf("No people to delete.\n");
        return;
    }

    createMaxHeap_076(*people_076, *n_076);
    printf("Deleting person with ID: %d\n", (*people_076)[0].id_076);

    free((*people_076)[0].name_076);
    (*people_076)[0] = (*people_076)[*n_076 - 1];
    (*n_076)--;

    *people_076 = (struct person *)realloc(*people_076, (*n_076) * sizeof(struct person));

    maxHeapify_076(*people_076, *n_076, 0);
}

void minHeapify_076(struct person *people_076, int n_076, int i_076) {
    int smallest_076 = i_076;
    int left_076 = 2 * i_076 + 1;
    int right_076 = 2 * i_076 + 2;

    if (left_076 < n_076 && people_076[left_076].age_076 < people_076[smallest_076].age_076)
        smallest_076 = left_076;

    if (right_076 < n_076 && people_076[right_076].age_076 < people_076[smallest_076].age_076)
        smallest_076 = right_076;

    if (smallest_076 != i_076) {
        swap_076(&people_076[i_076], &people_076[smallest_076]);
        minHeapify_076(people_076, n_076, smallest_076);
    }
}

void maxHeapify_076(struct person *people_076, int n_076, int i_076) {
    int largest_076 = i_076;
    int left_076 = 2 * i_076 + 1;
    int right_076 = 2 * i_076 + 2;

    if (left_076 < n_076 && people_076[left_076].weight_076 > people_076[largest_076].weight_076)
        largest_076 = left_076;

    if (right_076 < n_076 && people_076[right_076].weight_076 > people_076[largest_076].weight_076)
        largest_076 = right_076;

    if (largest_076 != i_076) {
        swap_076(&people_076[i_076], &people_076[largest_076]);
        maxHeapify_076(people_076, n_076, largest_076);
    }
}

//Display heap function
void displayHeap(struct person *people_076, int n_076) {
    for (int i_076 = 0; i_076 < n_076; i_076++) {
        printf("ID: %d\n", people_076[i_076].id_076);
        printf("Name: %s\n", people_076[i_076].name_076);
        printf("Age: %d\n", people_076[i_076].age_076);
        printf("Height: %d\n", people_076[i_076].height_076);
        printf("Weight: %d\n", people_076[i_076].weight_076);
        printf("\n");
    }
}




int main() {
    struct person *people_076 = NULL;
    int n_076 = 0;
    int choice_076;

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice_076);

        switch (choice_076) {
            case 1:
                readData_076(&people_076, &n_076);
                break;
            case 2:
                createMinHeap_076(people_076, n_076);
                printf("Min-heap created based on age.\n");
                break;
            case 3:
                createMaxHeap_076(people_076, n_076);
                printf("Max-heap created based on weight.\n");
                break;
            case 4:
                displayWeightOfYoungest_076(people_076, n_076);
                break;
            case 5:
                insertPersonMinHeap_076(&people_076, &n_076);
                break;
            case 6:
                deleteOldestPerson_076(&people_076, &n_076);
                break;
            case 7:
                displayHeap(people_076, n_076);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice_076 != 8);

   
    // for (int i_076 = 0; i_076 < n_076; i_076++) {
    //     free(people_076[i_076].name_076);
    // }
    // free(people_076);

    return 0;
}
