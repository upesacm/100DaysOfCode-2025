#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct StackNode {
    TreeNode *node;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, TreeNode *node) {
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = s->top;
    s->top = newNode;
}

TreeNode* pop(Stack *s) {
    if (s->top == NULL) return NULL;
    StackNode *temp = s->top;
    TreeNode *node = temp->node;
    s->top = s->top->next;
    free(temp);
    return node;
}

bool isEmptyStack(Stack *s) {
    return s->top == NULL;
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool findTarget(TreeNode* root, int k) {
    if (root == NULL) return false;
    
    Stack* s1 = createStack(); // For inorder traversal (smallest to largest)
    Stack* s2 = createStack(); // For reverse inorder traversal (largest to smallest)
    
    TreeNode* curr1 = root;
    TreeNode* curr2 = root;
    
    int val1 = 0, val2 = 0;
    
    while (true) {
        while (curr1 != NULL) {
            push(s1, curr1);
            curr1 = curr1->left;
        }
        while (curr2 != NULL) {
            push(s2, curr2);
            curr2 = curr2->right;
        }
        
        if (isEmptyStack(s1) || isEmptyStack(s2)) break;
        
        TreeNode* top1 = s1->top->node;
        TreeNode* top2 = s2->top->node;
        
        if (top1 == top2) break;
        
        val1 = top1->val;
        val2 = top2->val;
        
        if (val1 + val2 == k) {
            return true;
        } else if (val1 + val2 < k) {
            curr1 = pop(s1)->right;
        } else {
            curr2 = pop(s2)->left;
        }
    }
    
    return false;
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(5);
    root1->left = createNode(3);
    root1->right = createNode(6);
    root1->left->left = createNode(2);
    root1->left->right = createNode(4);
    root1->right->right = createNode(7);
    int target1 = 9;
    printf("Input Tree:\n  5\n / \\\n3   6\n/ \\   \\\n2   4   7\n");
    printf("Target = %d\n", target1);
    printf("Output: %s\n", findTarget(root1, target1) ? "Yes" : "No");

    // Example 2
    int target2 = 28;
    printf("\nInput Tree:\n  5\n / \\\n3   6\n/ \\   \\\n2   4   7\n");
    printf("Target = %d\n", target2);
    printf("Output: %s\n", findTarget(root1, target2) ? "Yes" : "No");
    
    return 0;
}
