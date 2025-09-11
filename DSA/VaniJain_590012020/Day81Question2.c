#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *left, *right;
};
struct ListNode 
{
    int data;
    struct ListNode* next;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
struct ListNode* createListNode(int value) 
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void inorderToList(struct Node* root, struct ListNode** head, struct ListNode** tail) 
{
    if (root == NULL) return;
    inorderToList(root->left, head, tail);
    struct ListNode* newNode = createListNode(root->data);
    if (*head == NULL) 
    {
        *head = *tail = newNode;
    } 
    else 
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    inorderToList(root->right, head, tail);
}
int main() 
{
    struct Node* root = NULL;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int n, val;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    inorderToList(root, &head, &tail);
    printf("Sorted Linked List: ");
    struct ListNode* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
