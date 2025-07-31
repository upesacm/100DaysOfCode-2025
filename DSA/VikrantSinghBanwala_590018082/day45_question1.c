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
int sumQueue(Queue* q) {
    int sum = 0;
    Queue* temp = createQueue();
    while (q->front != NULL) {
        int val = dequeue(q);
        sum += val;
        enqueue(temp, val);
    }
    while (temp->front != NULL) {
        enqueue(q, dequeue(temp));
    }
    free(temp);
    return sum;
}
int main() {
    Queue* q1 = createQueue();
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    printf("%d\n", sumQueue(q1));
    Queue* q2 = createQueue();
    enqueue(q2, 10);
    enqueue(q2, 20);
    enqueue(q2, 30);
    printf("%d\n", sumQueue(q2));
    return 0;
}