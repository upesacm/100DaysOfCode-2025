#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    int hd;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode *node;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, TreeNode *node) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

TreeNode* dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    TreeNode *node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->hd = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void getVerticalOrder(TreeNode* root) {
    if (root == NULL) return;

    int min_hd = 0, max_hd = 0;
    
    Queue* q = createQueue();
    root->hd = 0;
    enqueue(q, root);
    
    // Determine min and max HD
    Queue* temp_q = createQueue();
    enqueue(temp_q, root);
    while(!isEmpty(temp_q)) {
        TreeNode* current = dequeue(temp_q);
        if (current->hd < min_hd) min_hd = current->hd;
        if (current->hd > max_hd) max_hd = current->hd;
        if (current->left) {
            current->left->hd = current->hd - 1;
            enqueue(temp_q, current->left);
        }
        if (current->right) {
            current->right->hd = current->hd + 1;
            enqueue(temp_q, current->right);
        }
    }
    
    int num_cols = max_hd - min_hd + 1;
    int** result = (int**)malloc(num_cols * sizeof(int*));
    int* counts = (int*)calloc(num_cols, sizeof(int));
    int* sizes = (int*)calloc(num_cols, sizeof(int));

    // Reset queue and HDs for actual traversal
    q = createQueue();
    root->hd = 0;
    enqueue(q, root);
    
    while (!isEmpty(q)) {
        TreeNode *current = dequeue(q);
        int col_idx = current->hd - min_hd;

        if (counts[col_idx] == sizes[col_idx]) {
            sizes[col_idx] = (sizes[col_idx] == 0) ? 1 : sizes[col_idx] * 2;
            result[col_idx] = (int*)realloc(result[col_idx], sizes[col_idx] * sizeof(int));
        }
        result[col_idx][counts[col_idx]++] = current->val;

        if (current->left) {
            current->left->hd = current->hd - 1;
            enqueue(q, current->left);
        }
        if (current->right) {
            current->right->hd = current->hd + 1;
            enqueue(q, current->right);
        }
    }

    printf("[\n");
    for (int i = 0; i < num_cols; i++) {
        printf("  [");
        for (int j = 0; j < counts[i]; j++) {
            printf("%d%s", result[i][j], (j == counts[i] - 1) ? "" : ",");
        }
        printf("]%s\n", (i == num_cols - 1) ? "" : ",");
        free(result[i]);
    }
    printf("]\n");

    free(result);
    free(counts);
    free(sizes);
    free(q);
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);
    printf("Example 1 Output:\n");
    getVerticalOrder(root1);
    
    // Example 2
    TreeNode* root2 = createNode(4);
    root2->left = createNode(2);
    root2->right = createNode(6);
    root2->left->left = createNode(1);
    root2->left->right = createNode(3);
    root2->right->left = createNode(5);
    root2->right->right = createNode(7);
    printf("\nExample 2 Output:\n");
    getVerticalOrder(root2);

    return 0;
}
