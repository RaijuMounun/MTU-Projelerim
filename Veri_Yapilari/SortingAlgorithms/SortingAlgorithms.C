#include <stdio.h>
#include <stdlib.h>

#pragma region Linked List
int maxRandRange = 100;
int minRandRange = 0;

struct node // Node Struct
{
    int data;
    struct node *next;
};
struct node *root = NULL;

node *NewNode(int ndata, struct node *nnext)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ndata;
    temp->next = nnext;
    return temp;
}

void AddNodeToEnd(int nodeData)
{
    struct node *temp = NewNode(nodeData, NULL); // New node
    if (root == NULL)
    {
        root = temp;
        return;
    }
    struct node *iter = root; // Iterator
    while (iter->next != NULL)
    {
        iter = iter->next; // Go until last node
    }
    iter->next = temp; // Set new node as last node
}

void MakeList(int size, int datas[])
{
    for (int i = 0; i < size; i++)
    {
        AddNodeToEnd(datas[i]);
    }
}

void PrintList()
{
    printf("Linked List: ");
    struct node *iter = root;
    while (iter != NULL)
    {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("NULL\n\n");
}

void ConstructList() //
{
    printf("List size: ");
    int listSize = scanf("%d", listSize);

    int datas[listSize];
    for (int i = 0; i < listSize; i++)
    {
        datas[i] = rand() % (maxRandRange + 1);
    }
    MakeList(listSize, datas);
    PrintList();
}

#pragma endregion