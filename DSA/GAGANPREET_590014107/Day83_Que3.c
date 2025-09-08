#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


void inorder(struct Node* root, int* arr, int* index)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorder(root->right, arr, index);
}


int twoSum(struct Node* root, int target)
{
    int arr[1000];
    int size = 0;

    inorder(root, arr, &size);

    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
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
    struct Node* root = create(5);
    root->left = create(3);
    root->right = create(6);
    root->left->left = create(2);
    root->left->right = create(4);
    root->right->right = create(7);

    int target = 9;
    printf("Two Sum Exists? %s\n", twoSum(root, target) ? "Yes" : "No");  

    target = 28;
    printf("Two Sum Exists? %s\n", twoSum(root, target) ? "Yes" : "No");  

    return 0;
}
