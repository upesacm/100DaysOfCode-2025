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

bool areQueuesEqual(Queue* q1, Queue* q2) {
    if (q1->size != q2->size) {
        return false;
    }
    Node* curr1 = q1->front;
    Node* curr2 = q2->front;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data != curr2->data) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}

void freeQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
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

    printf("The queues are %s.\n", areQueuesEqual(q1, q2) ? "equal" : "not equal");

    freeQueue(q1);
    freeQueue(q2);

    return 0;
}
