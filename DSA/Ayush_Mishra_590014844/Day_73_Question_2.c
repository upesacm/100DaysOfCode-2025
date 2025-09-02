#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* nodes[100];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    nodes[rear++] = node;
}

struct Node* dequeue() {
    return nodes[front++];
}

int isEmpty() {
    return front == rear;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isEmpty()) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* tree[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        tree[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right child indices of node %d (-1 for NULL): ", i + 1);
        scanf("%d %d", &l, &r);
        if (l != -1) tree[i]->left = tree[l];
        if (r != -1) tree[i]->right = tree[r];
    }

    printf("Level Order Traversal: ");
    levelOrder(tree[0]);
    return 0;
}
