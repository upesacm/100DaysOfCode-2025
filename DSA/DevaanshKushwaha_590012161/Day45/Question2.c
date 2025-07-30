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

// Function to get the size of the queue (non-destructive)
int getQueueSize(Queue* q) {
    int count = 0;
    QNode* current = q->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to compare two queues for identical order and content
// This function modifies the queues temporarily but restores them to their original state.
int compareQueues(Queue* q1, Queue* q2) {
    if (getQueueSize(q1) != getQueueSize(q2)) {
        return 0; // Not identical if sizes differ
    }

    int size = getQueueSize(q1);
    int isEqual = 1;

    // Temporarily store elements to restore queues later
    int* tempArr1 = (int*)malloc(size * sizeof(int));
    int* tempArr2 = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tempArr1[i] = deQueue(q1);
        tempArr2[i] = deQueue(q2);
        if (tempArr1[i] != tempArr2[i]) {
            isEqual = 0;
        }
    }

    // Restore original queues
    for (int i = 0; i < size; i++) {
        enQueue(q1, tempArr1[i]);
        enQueue(q2, tempArr2[i]);
    }

    free(tempArr1);
    free(tempArr2);

    return isEqual;
}

int main() {
    Queue* q1 = createQueue();
    Queue* q2 = createQueue();
    int numElements1, numElements2, value;

    printf("Enter the number of elements for Queue 1: ");
    scanf("%d", &numElements1);
    printf("Enter %d integer elements for Queue 1:\n", numElements1);
    for (int i = 0; i < numElements1; i++) {
        scanf("%d", &value);
        enQueue(q1, value);
    }

    printf("Enter the number of elements for Queue 2: ");
    scanf("%d", &numElements2);
    printf("Enter %d integer elements for Queue 2:\n", numElements2);
    for (int i = 0; i < numElements2; i++) {
        scanf("%d", &value);
        enQueue(q2, value);
    }

    if (compareQueues(q1, q2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory for q1
    while (!isEmptyQueue(q1)) {
        deQueue(q1);
    }
    free(q1);

    // Free allocated memory for q2
    while (!isEmptyQueue(q2)) {
        deQueue(q2);
    }
    free(q2);

    return 0;
}
