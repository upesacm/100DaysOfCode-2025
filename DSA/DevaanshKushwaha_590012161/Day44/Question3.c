#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

// Structure for the Queue
typedef struct Queue {
    QNode *front, *rear;
} Queue;

// Function to create a new queue node
QNode* newQNode(int k) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue (enqueue)
void enQueue(Queue* q, int k) {
    QNode* temp = newQNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue (dequeue)
int deQueue(Queue* q) {
    if (q->front == NULL) return -1; // Return -1 for empty queue
    QNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

int main() {
    Queue* q1 = createQueue(); // An empty queue
    Queue* q2 = createQueue(); // A non-empty queue

    int numElements, value;

    // Test with an empty queue
    printf("--- Testing with an empty queue ---\n");
    if (isEmptyQueue(q1)) {
        printf("Queue is Empty: True\n");
    } else {
        printf("Queue is Empty: False\n");
    }

    // Test with a non-empty queue
    printf("\n--- Testing with a non-empty queue ---\n");
    printf("Enter the number of elements for the queue: ");
    scanf("%d", &numElements);

    printf("Enter %d integer elements:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &value);
        enQueue(q2, value);
    }

    if (isEmptyQueue(q2)) {
        printf("Queue is Empty: True\n");
    } else {
        printf("Queue is Empty: False\n");
    }

    // Free allocated memory for q1
    free(q1);

    // Free allocated memory for q2
    while (!isEmptyQueue(q2)) {
        deQueue(q2);
    }
    free(q2);

    return 0;
}
