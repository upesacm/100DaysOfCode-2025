#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
struct Node* reverse(struct Node* head) 
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
bool isPalindrome(struct Node* head) 
{
    if (head == NULL || head->next == NULL)
        return true;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* secondHalf = reverse(slow->next);
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf;
    bool result = true;
    while (temp) 
    {
        if (firstHalf->data != temp->data) 
        {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    slow->next = reverse(secondHalf);
    return result;
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
int main() 
{
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d positive integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Linked list: ");
    printList(head);
    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");
    return 0;
}
