#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void addToArray(int* arr, int* size, int val) 
{
    arr[*size] = val;
    (*size)++;
}
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int isPresent(int* arr, int size, int val) 
{
    for (int i = 0; i < size; i++)
        if (arr[i] == val) return 1;
    return 0;
}
struct Node* makeUnion(struct Node* head1, struct Node* head2) 
{
    int arr[1000]; 
    int size = 0;

    while (head1) 
    {
        if (!isPresent(arr, size, head1->data))
            addToArray(arr, &size, head1->data);
        head1 = head1->next;
    }
    while (head2)
      {
        if (!isPresent(arr, size, head2->data))
            addToArray(arr, &size, head2->data);
        head2 = head2->next;
    }
    qsort(arr, size, sizeof(int), compare);

    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < size; i++)
      {
        struct Node* temp = newNode(arr[i]);
        if (!head) 
        {
            head = temp;
            tail = temp;
        } 
        else 
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}
void printList(struct Node* head) 
{
    while (head) 
    {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* l1 = newNode(9);
    l1->next = newNode(6);
    l1->next->next = newNode(4);
    l1->next->next->next = newNode(2);
    l1->next->next->next->next = newNode(3);
    l1->next->next->next->next->next = newNode(8);

    struct Node* l2 = newNode(1);
    l2->next = newNode(2);
    l2->next->next = newNode(8);
    l2->next->next->next = newNode(6);
    l2->next->next->next->next = newNode(2);

    struct Node* result = makeUnion(l1, l2);
    printf("Union: ");
    printList(result);
    return 0;
}
