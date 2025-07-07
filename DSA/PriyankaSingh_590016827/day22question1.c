#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertEnd(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
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

// Function to find the middle node using two-pointer approach
void findMiddle(struct Node* head) 
{
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL)
        printf("Middle node: %d\n", slow->data);
}

// Function to print the list (optional)
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Linked List: ");
    printList(head);

    findMiddle(head);

    return 0;
}
