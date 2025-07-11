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
struct Node* sortList(struct Node* head)
{
    struct Node *zeroD = newNode(0), *oneD = newNode(0), *twoD = newNode(0);
    struct Node *zero = zeroD, *one = oneD, *two = twoD;

    struct Node* curr = head;

    while (curr) 
    {
        if (curr->data == 0) 
        {
            zero->next = curr;
            zero = zero->next;
        } 
        else if (curr->data == 1) 
        {
            one->next = curr;
            one = one->next;
        } 
        else
        {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;

    head = zeroD->next;

    free(zeroD);
    free(oneD);
    free(twoD);

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
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(0);
    head->next->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next->next = newNode(2);
    printf("Original List: ");
    printList(head);

    head = sortList(head);
    printf("Sorted List: ");
    printList(head);
    return 0;
}
