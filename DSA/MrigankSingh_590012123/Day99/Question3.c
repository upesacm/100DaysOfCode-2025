#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Binary tree node structure
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Structure to hold tree and node count
typedef struct {
    Node* root;
    int nodeCount;
} Tree;

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (tree == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    tree->root = NULL;
    tree->nodeCount = 0;
    return tree;
}

// Function to insert nodes (level-order input)
Node* insertNode(Node* root, int val, int* nodeCount) {
    if (val == -1) return root; // -1 represents NULL

    (*nodeCount)++;
    if (root == NULL) {
        return createNode(val);
    }

    // Use queue for level-order insertion
    Node** queue = (Node**)malloc((*nodeCount) * sizeof(Node*));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = createNode(val);
            free(queue);
            return root;
        } else if (current->right == NULL) {
            current->right = createNode(val);
            free(queue);
            return root;
        } else {
            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int maxPathSumUtil(Node* root, int* maxSum) {
    if (root == NULL) return 0;

    // Recursively compute max path sums for left and right subtrees
    int left = maxPathSumUtil(root->left, maxSum);
    int right = maxPathSumUtil(root->right, maxSum);

    // Consider single path through current node
    int maxSingle = max(max(left, right) + root->val, root->val);

    // Consider path through root (left -> root -> right)
    int maxTop = max(maxSingle, left + right + root->val);

    // Update global maximum
    *maxSum = max(*maxSum, maxTop);

    // Return maximum single path for parent
    return maxSingle;
}

int maxPathSum(Tree* tree) {
    if (tree->root == NULL) return 0;
    int maxSum = INT_MIN;
    maxPathSumUtil(tree->root, &maxSum);
    return maxSum;
}

int main() {
    Tree* tree = createTree();
    int n;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer for node count.\n");
        free(tree);
        return 1;
    }

    if (n == 0) {
        printf("0\n");
        free(tree);
        return 0;
    }

    printf("Enter the node values (level-order, use -1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        int val;
        printf("Node %d value: ", i);
        scanf("%d", &val);
        if (i == 0 && val == -1) {
            printf("Root cannot be NULL.\n");
            free(tree);
            return 1;
        }
        tree->root = insertNode(tree->root, val, &tree->nodeCount);
    }

    int result = maxPathSum(tree);
    printf("%d\n", result);

    freeTree(tree->root);
    free(tree);
    return 0;
}
