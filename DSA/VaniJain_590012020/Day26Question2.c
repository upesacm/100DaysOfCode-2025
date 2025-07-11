#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int val) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int val) 
{
    struct Node* newNode = createNode(val);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}
struct Node* makeUnion(struct Node* head1, struct Node* head2) 
{
    int arr[1000];  
    int index = 0:
    while (head1 != NULL) 
    {
        arr[index++] = head1->data;
        head1 = head1->next;
    }
    while (head2 != NULL) 
    {
        arr[index++] = head2->data;
        head2 = head2->next;
    }
    qsort(arr, index, sizeof(int), compare);
    struct Node* result = NULL;
    for (int i = 0; i < index; i++) 
    {
        if (i == 0 || arr[i] != arr[i - 1]) 
        {
            insertEnd(&result, arr[i]);
        }
    }
    return result;
}
int main() 
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n1, n2, val;t
    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);
    printf("Enter elements of first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertEnd(&head1, val);
    }
    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);
    printf("Enter elements of second list:\n");
    for (int i = 0; i < n2; i++) 
    {
        scanf("%d", &val);
        insertEnd(&head2, val);
    }
    struct Node* unionList = makeUnion(head1, head2);
    printf("Union of both lists (sorted & distinct): ");
    printList(unionList);
    return 0;
}
