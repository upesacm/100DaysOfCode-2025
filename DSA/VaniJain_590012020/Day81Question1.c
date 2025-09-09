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
struct HDMap 
{
    struct ListNode* list;
};
struct Node* createNode(int value) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
void appendList(struct ListNode** head, int value) 
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}
void findHDRange(struct Node* root, int hd, int* min, int* max) 
{
    if (root == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findHDRange(root->left, hd - 1, min, max);
    findHDRange(root->right, hd + 1, min, max);
}
void fillHDMap(struct Node* root, int hd, struct ListNode** hdMap, int offset) 
{
    if (root == NULL) return;
    appendList(&hdMap[hd + offset], root->data);
    fillHDMap(root->left, hd - 1, hdMap, offset);
    fillHDMap(root->right, hd + 1, hdMap, offset);
}
int main() 
{
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    int minHD = 0, maxHD = 0;
    findHDRange(root, 0, &minHD, &maxHD);
    int totalHD = maxHD - minHD + 1;
    struct ListNode** hdMap = (struct ListNode**)malloc(totalHD * sizeof(struct ListNode*));
    for (int i = 0; i < totalHD; i++) hdMap[i] = NULL;
    fillHDMap(root, 0, hdMap, -minHD);
    printf("Vertical order of BST:\n");
    for (int i = 0; i < totalHD; i++) 
    {
        struct ListNode* temp = hdMap[i];
        while (temp) 
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    free(hdMap);
    return 0;
}
