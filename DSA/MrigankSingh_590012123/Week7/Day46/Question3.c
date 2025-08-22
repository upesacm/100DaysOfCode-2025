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
        return -1;
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

void mergeQueues(Queue* q1, Queue* q2) {
    if (isEmpty(q1)) {
        q1->front = q2->front;
        q1->rear = q2->rear;
    } else if (!isEmpty(q2)) {
        q1->rear->next = q2->front;
        q1->rear = q2->rear;
    }
    q2->front = q2->rear = NULL;
    q1->size += q2->size;
    q2->size = 0;
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

void readQueueInput(Queue* queue, const char* queueName) {
    int n, data;
    printf("Enter the number of elements for %s: ", queueName);
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error: Invalid number of elements.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter %d elements for %s: ", n, queueName);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &data) != 1) {
            printf("Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        enqueue(queue, data);
    }
}

int main() {
    Queue* q1 = createQueue();
    Queue* q2 = createQueue();

    readQueueInput(q1, "Queue 1");
    readQueueInput(q2, "Queue 2");

    printf("\nQueue 1 before merge: ");
    printQueue(q1);
    printf("Queue 2 before merge: ");
    printQueue(q2);

    mergeQueues(q1, q2);

    printf("\nQueue 1 after merge: ");
    printQueue(q1);
    printf("Queue 2 after merge: ");
    printQueue(q2);

    freeQueue(q1);
    freeQueue(q2);

    return 0;
}
