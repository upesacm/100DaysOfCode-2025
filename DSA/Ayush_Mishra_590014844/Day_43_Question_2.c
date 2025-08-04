#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char str[20];
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(char* val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->str, val);
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

char* dequeue() {
    if (front == NULL) return NULL;
    Node* temp = front;
    char* val = (char*)malloc(20);
    strcpy(val, temp->str);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

int main() {
    int n, i;
    char *s, s0[20], s1[20];

    printf("Enter value of n: ");
    scanf("%d", &n);

    enqueue("1");

    for (i = 0; i < n; i++) {
        s = dequeue();
        printf("%s ", s);
        sprintf(s0, "%s0", s);
        sprintf(s1, "%s1", s);
        enqueue(s0);
        enqueue(s1);
        free(s);
    }

    return 0;
}
