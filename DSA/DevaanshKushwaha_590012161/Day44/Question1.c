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

// Function to display all elements of a queue without modifying it
void displayQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return;
    }
    QNode* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    int numElements, value;

    printf("Enter the number of elements for the queue: ");
    scanf("%d", &numElements);

    printf("Enter %d integer elements:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &value);
        enQueue(q, value);
    }

    printf("Elements of the queue: ");
    displayQueue(q); // Displaying the queue elements

    // Free allocated memory
    while (!isEmptyQueue(q)) {
        deQueue(q);
    }
    free(q);

    return 0;
}
