#include <stdio.h>
#define MAX 50
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear = rear + 1;
    queue[rear] = val;
}

void displayQueue() {
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, val, i;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    displayQueue();

    return 0;
}
