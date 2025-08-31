#include <stdio.h>

#define SIZE 100

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

void bfs(struct Node *root) {
    if (root == NULL)
        return;

    struct Node *q[SIZE];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        struct Node *cur = q[front++];
        printf("%d ", cur->val);
        if (cur->left)
            q[rear++] = cur->left;
        if (cur->right)
            q[rear++] = cur->right;
    }
}

// Example usage
int main() {
    struct Node a = {1, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {3, NULL, NULL};
    a.left = &b;
    a.right = &c;

    printf("Level Order: ");
    bfs(&a);  // Output: 1 2 3
    return 0;
}
