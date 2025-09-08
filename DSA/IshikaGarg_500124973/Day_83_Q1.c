#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

void enqueue(struct QNode** front, struct QNode** rear, struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (*rear) (*rear)->next = temp;
    else *front = temp;
    *rear = temp;
}

struct QNode* dequeue(struct QNode** front) {
    if (!*front) return NULL;
    struct QNode* temp = *front;
    *front = (*front)->next;
    if (!*front) *front = NULL;
    return temp;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);

    int minHD = 0, maxHD = 0;
    int map[100][100]; // store values grouped by HD
    int count[100] = {0}; // count nodes per HD

    while (front) {
        struct QNode* qn = dequeue(&front);
        struct Node* node = qn->node;
        int hd = qn->hd;

        int idx = hd + 50; // shift index to handle negative HD
        map[idx][count[idx]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left) enqueue(&front, &rear, node->left, hd - 1);
        if (node->right) enqueue(&front, &rear, node->right, hd + 1);
        free(qn);
    }

    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 50;
        printf("[");
        for (int j = 0; j < count[idx]; j++) {
            printf("%d", map[idx][j]);
            if (j < count[idx] - 1) printf(",");
        }
        printf("] ");
    }
    printf("\n");
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Vertical Order: ");
    verticalOrder(root); // Expected [[9], [3,15], [20], [7]]
    return 0;
}

