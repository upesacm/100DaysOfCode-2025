#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree() 
{
    int val;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);
    if (val == -1) return NULL;
    struct Node* root = createNode(val);
    printf("Enter left child of %d\n", val);
    root->left = buildTree();
    printf("Enter right child of %d\n", val);
    root->right = buildTree();
    return root;
}
struct Queue 
{
    struct Node* data;
    int level;
    struct Queue* next;
};
void enqueue(struct Queue** front, struct Queue** rear, struct Node* node, int level) 
{
    struct Queue* newElement = (struct Queue*)malloc(sizeof(struct Queue));
    newElement->data = node;
    newElement->level = level;
    newElement->next = NULL;
    if (*rear == NULL) 
    {
        *front = *rear = newElement;
    } 
    else 
    {
        (*rear)->next = newElement;
        *rear = newElement;
    }
}
struct Node* dequeue(struct Queue** front, struct Queue** rear, int* level) 
{
    if (*front == NULL) return NULL;
    struct Queue* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    struct Node* node = temp->data;
    *level = temp->level;
    free(temp);
    return node;
}
void printLeftmostNodes(struct Node* root) 
{
    if (root == NULL) return;
    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);
    int currentLevel = -1;
    while (front != NULL) 
    {
        int level;
        struct Node* node = dequeue(&front, &rear, &level);
        if (level > currentLevel) 
        {
            printf("%d ", node->data);
            currentLevel = level;
        }
        if (node->left != NULL) enqueue(&front, &rear, node->left, level + 1);
        if (node->right != NULL) enqueue(&front, &rear, node->right, level + 1);
    }
    printf("\n");
}
int main() 
{
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();
    printf("Leftmost nodes at each level: ");
    printLeftmostNodes(root);
    return 0;
}
