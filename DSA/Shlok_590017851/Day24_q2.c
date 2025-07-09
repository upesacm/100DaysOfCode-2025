#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct Node* head)
{
    while (head != NULL) 
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}
void deleteNafterM(struct Node* head, int m, int n) 
{
    struct Node* current = head;
    struct Node* temp;
    
    while (current != NULL) 
    {
        for (int i = 1; i < m && current != NULL; i++)
            current = current->next;
        if (current == NULL)
            return;
        temp = current->next;
        for (int i = 0; i < n && temp != NULL; i++) 
        {
            struct Node* nodeToDelete = temp;
            temp = temp->next;
            free(nodeToDelete);
        }
        current->next = temp;
        current = temp;
    }
}
int main()
{
    struct Node* head = createNode(9);
    head->next = createNode(1);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(9);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(10);
    head->next->next->next->next->next->next->next = createNode(1);

    int m = 2, n = 1;

    printf("Original List:\n");
    printList(head);

    deleteNafterM(head, m, n);

    printf("Modified List after deleting %d nodes after every %d nodes:\n", n, m);
    printList(head);

    return 0;
}
