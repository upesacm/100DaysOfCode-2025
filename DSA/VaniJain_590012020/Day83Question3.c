#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
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
void inorder(struct Node* root, int arr[], int* index) 
{
    if (root == NULL) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorder(root->right, arr, index);
}
int hasPairWithSum(struct Node* root, int target, int n) 
{
    int arr[1000], index = 0;
    inorder(root, arr, &index);
    int left = 0, right = index - 1;
    while (left < right) 
    {
        int sum = arr[left] + arr[right];
        if (sum == target) 
        {
            printf("Pair found: %d + %d = %d\n", arr[left], arr[right], target);
            return 1;
        } 
        else if (sum < target) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return 0;
}
int main() 
{
    struct Node* root = NULL;
    int n, val, target;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter target sum: ");
    scanf("%d", &target);
    if (!hasPairWithSum(root, target, n))
        printf("No pair with sum %d found in BST.\n", target);
    return 0;
}
