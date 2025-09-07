#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    int hd; // Horizontal distance
};

struct Queue {
    struct QueueNode** array;
    int front, rear, size, capacity;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct MapNode {
    int hd;
    struct ListNode* list;
    struct MapNode* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d (BST order)\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d (BST order)\n", data);
    root->right = createTree();
    return root;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct QueueNode**)malloc(capacity * sizeof(struct QueueNode*));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, struct Node* treeNode, int hd) {
    struct QueueNode* qNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    qNode->treeNode = treeNode;
    qNode->hd = hd;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = qNode;
    queue->size++;
}

struct QueueNode* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) return NULL;
    struct QueueNode* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

struct MapNode* createMapNode(int hd, int data) {
    struct MapNode* mapNode = (struct MapNode*)malloc(sizeof(struct MapNode));
    mapNode->hd = hd;
    mapNode->list = (struct ListNode*)malloc(sizeof(struct ListNode));
    mapNode->list->data = data;
    mapNode->list->next = NULL;
    mapNode->next = NULL;
    return mapNode;
}

void addToMap(struct MapNode** map, int hd, int data) {
    struct MapNode* current = *map;
    struct MapNode* prev = NULL;
    
    while (current && current->hd < hd) {
        prev = current;
        current = current->next;
    }
    
    if (current && current->hd == hd) {
        struct ListNode* newListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newListNode->data = data;
        newListNode->next = current->list;
        current->list = newListNode;
    } else {
        struct MapNode* newMapNode = createMapNode(hd, data);
        newMapNode->next = current;
        if (prev) {
            prev->next = newMapNode;
        } else {
            *map = newMapNode;
        }
    }
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;
    
    struct Queue* queue = createQueue(100);
    struct MapNode* map = NULL;
    
    enqueue(queue, root, 0);
    
    while (!isQueueEmpty(queue)) {
        struct QueueNode* qNode = dequeue(queue);
        struct Node* node = qNode->treeNode;
        int hd = qNode->hd;
        
        addToMap(&map, hd, node->data);
        
        if (node->left) enqueue(queue, node->left, hd - 1);
        if (node->right) enqueue(queue, node->right, hd + 1);
        
        free(qNode);
    }
    
    printf("Vertical order traversal: ");
    struct MapNode* current = map;
    while (current) {
        printf("[");
        struct ListNode* list = current->list;
        while (list) {
            printf("%d", list->data);
            if (list->next) printf(",");
            list = list->next;
        }
        printf("]");
        if (current->next) printf(",");
        current = current->next;
    }
    printf("\n");
    
    free(queue->array);
    free(queue);
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    verticalOrder(root);
    return 0;
}
