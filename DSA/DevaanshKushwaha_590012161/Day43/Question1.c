#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

QNode* newQNode(int k) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, int k) {
    QNode* temp = newQNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int deQueue(Queue* q) {
    if (q->front == NULL) return -1;
    QNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

typedef struct Stack {
    SNode* top;
} Stack;

SNode* newSNode(int data) {
    SNode* stackNode = (SNode*)malloc(sizeof(SNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int data) {
    SNode* stackNode = newSNode(data);
    stackNode->next = s->top;
    s->top = stackNode;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;
    SNode* temp = s->top;
    s->top = s->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int main() {
    Queue* q = createQueue();
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enQueue(q, val);
    }

    Stack* s = createStack();

    for (int i = 0; i < k; i++) {
        push(s, deQueue(q));
    }

    while (s->top != NULL) {
        enQueue(q, pop(s));
    }

    for (int i = 0; i < n - k; i++) {
        enQueue(q, deQueue(q));
    }

    while (!isEmptyQueue(q)) {
        printf("%d ", deQueue(q));
    }
    printf("\n");

    free(q);
    free(s);

    return 0;
}
