#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Indicates empty queue
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void removeAllOccurrences(Queue* queue, int x) {
    if (isEmpty(queue)) return;

    Queue* tempQueue = createQueue();
    int current;
    int originalSize = queue->size;
    
    for (int i = 0; i < originalSize; i++) {
        current = dequeue(queue);
        if (current != x) {
            enqueue(tempQueue, current);
        }
    }
    
    while (!isEmpty(tempQueue)) {
        enqueue(queue, dequeue(tempQueue));
    }
    
    freeQueue(tempQueue);
}

void printQueue(Queue* queue) {
    Node* current = queue->front;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void readQueueInput(Queue* queue) {
    int n, data;
    printf("Enter the number of elements in the queue: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of elements.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data) != 1) {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        enqueue(queue, data);
    }
}

int main() {
    Queue* queue = createQueue();
    readQueueInput(queue);

    int x;
    printf("Enter the element to remove: ");
    if (scanf("%d", &x) != 1) {
        printf("Error: Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nQueue before removal: ");
    printQueue(queue);
    
    removeAllOccurrences(queue, x);
    
    printf("Queue after removal: ");
    printQueue(queue);

    freeQueue(queue);
    return 0;
}
