#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node 
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
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

// Function to count occurrences of a key
int countOccurrences(struct Node* head, int key) 
{
    int count = 0;
    while (head != NULL) 
    {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
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
    int n, value, key;

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    printf("Linked List: ");
    printList(head);

    int freq = countOccurrences(head, key);
    printf("Frequency of %d: %d\n", key, freq);

    return 0;
}
