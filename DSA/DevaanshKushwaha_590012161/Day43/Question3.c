#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode {
    char data;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

QNode* newQNode(char k) {
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

void enQueue(Queue* q, char k) {
    QNode* temp = newQNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

char deQueue(Queue* q) {
    if (q->front == NULL) return '\0';
    QNode* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

typedef struct SNode {
    char data;
    struct SNode* next;
} SNode;

typedef struct Stack {
    SNode* top;
} Stack;

SNode* newSNode(char data) {
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

void push(Stack* s, char data) {
    SNode* stackNode = newSNode(data);
    stackNode->next = s->top;
    s->top = stackNode;
}

char pop(Stack* s) {
    if (s->top == NULL) return '\0';
    SNode* temp = s->top;
    s->top = s->top->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

int isEmptyStack(Stack* s) {
    return s->top == NULL;
}

int main() {
    Queue* q = createQueue();
    Stack* s = createStack();
    char inputChar;
    int count = 0;

    while (scanf(" %c", &inputChar) == 1) {
        if (inputChar == '\n' || inputChar == EOF) break;
        enQueue(q, inputChar);
        push(s, inputChar);
        count++;
    }

    int isPalindrome = 1;
    for (int i = 0; i < count; i++) {
        if (deQueue(q) != pop(s)) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    while (!isEmptyQueue(q)) {
        deQueue(q);
    }
    free(q);

    while (!isEmptyStack(s)) {
        pop(s);
    }
    free(s);

    return 0;
}
