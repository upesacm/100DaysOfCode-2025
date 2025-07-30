#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}
int findMaxInQueue(Queue* q) {
    int max = -1; 
    Queue* temp = createQueue();
    while (q->front != NULL) {
        int val = dequeue(q);
        if (val > max) {
            max = val;
        }
        enqueue(temp, val);
    }    
    while (temp->front != NULL) {
        enqueue(q, dequeue(temp));
    }
    free(temp);
    return max;
}
int main() {
    Queue* q1 = createQueue();
    enqueue(q1, 3);
    enqueue(q1, 5);
    enqueue(q1, 1);
    enqueue(q1, 2);
    printf("%d\n", findMaxInQueue(q1));
    Queue* q2 = createQueue();
    enqueue(q2, 10);
    enqueue(q2, 7);
    enqueue(q2, 4);
    printf("%d\n", findMaxInQueue(q2));
    return 0;
}