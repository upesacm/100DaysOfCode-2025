#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int n) {
    struct Node* nodes[MAX];
    int i, val, l, r;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        nodes[i] = newNode(val);
    }
    for (i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        if (l != -1) nodes[i]->left = nodes[l];
        if (r != -1) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

void leftView(struct Node* root) {
    struct Node* queue[MAX];
    int front = 0, rear = 0;
    if (!root) return;
    queue[rear++] = root;
    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];
            if (i == 0) printf("%d ", curr->data);
            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* root = buildTree(n);
    leftView(root);
    return 0;
}
