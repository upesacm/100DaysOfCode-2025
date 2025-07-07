#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int val;
    struct Node* nxt;
};
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->nxt = NULL;
    return node;
}
void printList(struct Node* head) 
{
    struct Node* curr = head;
    while (curr != NULL) 
    {
        printf("%d ", curr->val);
        curr = curr->nxt;
    }
}
int main() 
{
    struct Node* head = newNode(1);
    head->nxt = newNode(2);
    head->nxt->nxt = newNode(3);
    head->nxt->nxt->nxt = newNode(4);
    head->nxt->nxt->nxt->nxt = newNode(5);
    printf("Linked List: ");
    printList(head);
    printf("\n");
    struct Node* curr = head;
    struct Node* nxt;
    while (curr != NULL) 
    {
        nxt = curr->nxt;
        free(curr);
        curr = nxt;
    }
    return 0;
}
