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
struct Node* removeEveryKthNode(struct Node* head, int k)
{
    if (head == NULL || k <= 0)
        return head;

    if (k == 1) 
    {
        struct Node* temp;
        while (head != NULL)
          {
            temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL)
      {
        if (count % k == 0) 
        {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } 
        else 
        {
            prev = current;
            current = current->next;
        }
        count++;
    }
    return head;
}
void printList(struct Node* head)
{
    while (head != NULL) 
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* head = createNode(1);
    struct Node* temp = head;
    for (int i = 2; i <= 10; i++)
      {
        temp->next = createNode(i);
        temp = temp->next;
    }
    printf("Original list:\n");
    printList(head);
  
    int k = 3;
    head = removeEveryKthNode(head, k);
    printf("List after removing every %d-th node:\n", k);
    printList(head);
    return 0;
}
