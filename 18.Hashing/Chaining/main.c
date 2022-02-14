#include <stdio.h>
#include <stdlib.h>
#include "chains.h"

int hash(int key)
{
    return key % 10;
}

void insert(Node *H[], int key)
{
    int index = hash(key);
    insert_sorted(&H[index], key);
}

int main()
{
    Node *HT[10];
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    
    Node *temp = linear_search(HT[hash(22)], 22);

    if (temp)
    {
        printf("%d\n", temp->data);
    }
    else
    {
        printf("Element not found.\n");
    }
    

    

    return 0;
}
