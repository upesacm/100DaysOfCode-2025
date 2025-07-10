#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
void inputList(struct Node** head, int n) 
{
    int val;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        insertEnd(head, val);
    }
}
void printList(struct Node* head) 
{
    while (head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node* getIntersection(struct Node* head1, struct Node* head2) 
{
    struct Node* result = NULL;
    struct Node* tail = NULL;
    while (head1 && head2) 
    {
        if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data) 
        {
            head2 = head2->next;
        }
        else 
        {
            struct Node* newNode = createNode(head1->data);
            if (result == NULL) 
            {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return result;
}
int main() 
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersection = NULL;
    int n1, n2;
    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter %d elements (sorted in increasing order):\n", n1);
    inputList(&head1, n1);
    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter %d elements (sorted in increasing order):\n", n2);
    inputList(&head2, n2);
    intersection = getIntersection(head1, head2);
    printf("\nFirst List: ");
    printList(head1);
    printf("Second List: ");
    printList(head2);
    printf("Intersection List: ");
    printList(intersection);
    return 0;
}
