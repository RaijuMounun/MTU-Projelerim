#include <stdio.h>
#include <stdlib.h>

struct node // Singulary linked list
{
    int data;
    struct node *next;
};
struct node *root = NULL;

#pragma region Helpers

char *ChoicesArray[] = {"1- Make a list\n",
                        "2- Add node to start\n",
                        "3- Add node to place\n",
                        "4- Add node to index\n",
                        "5- Add node to end\n",
                        "6- Delete First Node\n",
                        "7- Delete Node At Index",
                        "8- Delete Node At Place\n",
                        "9- Delete Last Node\n"};

node *NewNode(int ndata, struct node *nnext)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ndata;
    temp->next = nnext;
    return temp;
}

int CheckLinkedListSize()
{
    struct node *iter = root;
    int size = 0;
    while (iter != NULL)
    {
        size++;
        iter = iter->next;
    }
    return size;
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

int GetArraySize(char *array[])
{
    int size = 0;
    while (array[size] != NULL)
    {
        size++;
    }
    return size;
}

node *GetLastNode()
{
    if (IsListEmpty())
        return NULL;
    if (root->next == NULL)
        return root;

    struct node *temp = root;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    return temp->next;
}
bool IsListEmpty()
{
    if (root != NULL)
        return false;
    printf("List is empty\n");
    return true;
}

#pragma endregion

#pragma region MakeList
void MakeList(int size, int datas[])
{
    for (int i = 0; i < size; i++)
    {
        AddNodeToEnd(datas[i]);
    }
}
void MakeListChoice(int size, int datas[], int data)
{
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    datas = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter the data of the %d. element: ", i + 1);
        scanf("%d", &data);
        datas[i] = data;
    }

    MakeList(size, datas);
    PrintList();
}
#pragma endregion

#pragma region Add Node

#pragma region Add Node To End
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
void AddNodeToEndChoice(int data)
{
    printf("Enter the data of the node: ");
    scanf("%d", &data);
    AddNodeToEnd(data);
    PrintList();
}
#pragma endregion

#pragma region Add Node To Start
void AddNodeToStart(int nodeData)
{
    root = NewNode(nodeData, root);
}
void AddNodeToStartChoice(int data)
{
    printf("Enter the data of the node: ");
    scanf("%d", &data);
    AddNodeToStart(data);
    PrintList();
}
#pragma endregion

#pragma region Add Node To Place
void AddNodeToPlace(int nodeData)
{
    struct node *temp = NewNode(nodeData, NULL); // New node
    if (root == NULL)
    {
        root = temp;
        return;
    }
    if (temp->data < root->data)
    {
        temp->next = root;
        root = temp;
        return;
    }
    struct node *iter = root; // Iterator
    while (iter->next != NULL && iter->next->data < nodeData)
    {
        iter = iter->next; // Go until last node
    }
    temp->next = iter->next; // Set new node as last node
    iter->next = temp;
}
void AddNodeToPlaceChoice(int data)
{
    printf("Enter the data of the node: ");
    scanf("%d", &data);
    AddNodeToPlace(data);
    PrintList();
}
#pragma endregion

#pragma region Add Node To Index
void AddNodeToIndex(int nodeData, int index)
{
    if (index < 0 || index > CheckLinkedListSize())
    {
        printf("Index out of range\n");
        return;
    }
    struct node *temp = NewNode(nodeData, NULL); // New node
    if (root == NULL)
    {
        root = temp;
        return;
    }
    struct node *iter = root; // Iterator
    if (index == 0)
    {
        temp->next = root;
        root = temp;
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        iter = iter->next; // Go to index-1
    }
    temp->next = iter->next; // Set new node as last node
    iter->next = temp;
}
void AddNodeToIndexChoice(int data, int index)
{
    printf("Enter the data of the node: ");
    scanf("%d", &data);
    printf("Enter the index of the node: ");
    scanf("%d", &index);
    AddNodeToIndex(data, index);
    PrintList();
}
#pragma endregion

#pragma endregion

#pragma region Delete Node

#pragma region Delete First Node
void DeleteFirstNode()
{
    if (root == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = root;
    root = root->next;
    free(temp);
}
void DeleteFirstNodeChoice()
{
    DeleteFirstNode();
    PrintList();
}
#pragma endregion

#pragma region Delete Node At Index
void DeleteNodeAtIndex(int index)
{
    if (index < 0 || index >= CheckLinkedListSize()) // İf list is empty
    {
        printf("Index out of range\n");
        return;
    }
    struct node *temp = root;
    if (index == 0) // İf index is 0
    {
        root = root->next;
        free(temp);
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}
void DeleteNodeAtIndexChoice(int index)
{
    printf("Enter the index of the node: ");
    DeleteNodeAtIndex(scanf("%d", &index));
    PrintList();
}
#pragma endregion

#pragma region Delete Node At Place
void DeleteNodeAtPlace(int nodeData)
{
    struct node *temp = root;
    if (root->data == nodeData)
    {
        root = root->next;
        free(temp);
        return;
    }
    while (temp->next != NULL && temp->next->data != nodeData)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Node not found\n");
        return;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}
void DeleteNodeAtPlaceChoice(int nodeData)
{
    printf("Enter the data of the node: ");
    DeleteNodeAtPlace(scanf("%d", &nodeData));
    PrintList();
}
#pragma endregion

#pragma region Delete Last Node
void DeleteLastNode()
{
    struct node *last = GetLastNode();
    if (last == root)
    {
        free(root);
        root = NULL;
        return;
    }
    if (last == NULL)
        return;

    free(last);
    last = NULL;
}
void DeleteLastNodeChoice()
{
    DeleteLastNode();
    PrintList();
}
#pragma endregion

#pragma endregion

#pragma region Convert List to Circular
void ConvertListToCircular()
{
    struct node *last = GetLastNode();
    if (last == NULL)
        return;
    last->next = root;
}

#pragma endregion

void ChoiceMake(int choice)
{
    int data, index, size;
    int *datas = NULL;
    switch (choice)
    {
    case 1:
        MakeListChoice(size, datas, data);
        break;
    case 2:
        AddNodeToStartChoice(data);
        break;
    case 3:
        AddNodeToPlaceChoice(data);
        break;
    case 4:
        AddNodeToIndexChoice(data, index);
        break;
    case 5:
        AddNodeToEndChoice(data);
        break;
    case 6:
        DeleteFirstNodeChoice();
        break;
    case 7:
        DeleteNodeAtIndexChoice(index);
        break;
    case 8:
        DeleteNodeAtPlaceChoice(data);
        break;
    case 9:
        DeleteLastNodeChoice();
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

void AskForChoice()
{
    int choice;
    PrintChoices(ChoicesArray);
    scanf("%d", &choice);
    ChoiceMake(choice);
}

void PrintChoices(char *choices[])
{
    printf("\n****MENU****\n");
    for (int i = 0; i < GetArraySize(choices); i++)
    {
        printf("Choice %d: %s", i + 1, choices[i]);
    }
    printf("Enter your choice (1,2,3,4,5,6,7,8,9): ");
}
int main()
{
    while (1)
    {
        AskForChoice();
    }
    return 0;
}