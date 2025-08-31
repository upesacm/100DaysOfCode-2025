#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int areIdentical(struct Node* root1, struct Node* root2) 
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}
int main() 
{
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    if (areIdentical(root1, root2))
        printf("The two trees are identical.\n");
    else
        printf("The two trees are NOT identical.\n");
    root2->right->data = 5;
    if (areIdentical(root1, root2))
        printf("The two trees are identical.\n");
    else
        printf("The two trees are NOT identical.\n");
    return 0;
}
