#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int findMax() {
    if (front == NULL)
        return INT_MIN;

    int maxVal = front->data;
    struct Node* temp = front->next;
    while (temp != NULL) {
        if (temp->data > maxVal)
            maxVal = temp->data;
        temp = temp->next;
    }
    return maxVal;
}

int main() {
    int n, val;
    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Maximum element in queue: %d\n", findMax());

    return 0;
}
