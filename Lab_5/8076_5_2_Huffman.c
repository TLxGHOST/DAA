// Aim  of  the  program:  Huffman  coding  assigns  variable  length  code  words  to  fixed  length 
// input  characters  based  on  their  frequencies  or  probabilities  of  occurrence.  Given  a  set  of 
// characters along with their frequency  of occurrences, write a c program to construct a Huffman 
// tree. 
// Note#  
// ● Declare  a  structure  SYMBOL  having  members  alphabet  and  frequency.  Create  a  Min-
// Priority Queue, keyed on frequency attributes.  
// ● Create an array of structures where size=number of alphabets. 
// Input:       
// Enter the number of distinct alphabets: 6 
// Enter the alphabets:       a       b       c       d       e       f
//  Enter its frequencies:    45     13       12     16       9       5 
// Output: 
// In-order traversal of the tree (Huffman): a  c  b  f  e  d 


#include<stdio.h>
#include<stdlib.h>

struct SYMBOL
{
    char alphabet;
    int frequency;
};

struct NODE
{
    struct SYMBOL symbol;
    struct NODE *left;
    struct NODE *right;
};

struct PRIORITY_QUEUE
{
    struct NODE *node;
    struct PRIORITY_QUEUE *next;
};

struct PRIORITY_QUEUE *front = NULL;

void enqueue(struct NODE *node)
{
    struct PRIORITY_QUEUE *new_node = (struct PRIORITY_QUEUE *)malloc(sizeof(struct PRIORITY_QUEUE));
    new_node->node = node;
    new_node->next = NULL;
    if (front == NULL)
    {
        front = new_node;
    }
    else
    {
        struct PRIORITY_QUEUE *temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

struct NODE *dequeue()
{
    if (front == NULL)
    {
        return NULL;
    }
    struct NODE *node = front->node;
    front = front->next;
    return node;
}



int main()
{
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);
    struct SYMBOL symbols[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the alphabet %d: ", i + 1);
        scanf(" %c", &symbols[i].alphabet);
        printf("Enter its frequency: ");
        scanf("%d", &symbols[i].frequency);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (symbols[i].frequency > symbols[j].frequency)
            {
                struct SYMBOL temp = symbols[i];
                symbols[i] = symbols[j];
                symbols[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c %d\n", symbols[i].alphabet, symbols[i].frequency);
    }

    for (int i = 0; i < n; i++)
    {
        struct NODE *node = (struct NODE *)malloc(sizeof(struct NODE));
        node->symbol = symbols[i];
        node->left = NULL;
        node->right = NULL;
        enqueue(node);
    }

    while (front->next != NULL)
    {
        struct NODE *left = dequeue();
        struct NODE *right = dequeue();
        struct NODE *node = (struct NODE *)malloc(sizeof(struct NODE));
        node->symbol.alphabet = ' ';
        node->symbol.frequency = left->symbol.frequency + right->symbol.frequency;
        node->left = left;
        node->right = right;
        enqueue(node);
    }

    struct NODE *root = dequeue();

    return 0;
}