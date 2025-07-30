#include<stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear = rear + 1;
    queue[rear] = val;
}

int isQueueEmpty() {
    if (front == -1) return 1;
    if (front > rear) return 1;
    return 0;
}

int main() {
    int n, val, i;
    printf("Enter number of elements to insert (0 for empty queue): ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter elements: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &val);
            enqueue(val);
        }
    }

    if (isQueueEmpty() == 1) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
