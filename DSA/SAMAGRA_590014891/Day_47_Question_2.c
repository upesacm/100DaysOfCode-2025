#include <stdio.h>

#define MAX 100

void insertFront(int queue[], int *front, int *rear, int element) {
    if (*front == 0) {
        printf("Cannot insert at front (no space)\n");
        return;
    }
    (*front)--;
    queue[*front] = element;
}

void printQueue(int queue[], int front, int rear) {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[MAX], front = MAX / 2, rear = MAX / 2 - 1;
    int n, element;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        rear++;
        scanf("%d", &queue[rear]);
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &element);
    insertFront(queue, &front, &rear, element);

    printf("Updated Queue: ");
    printQueue(queue, front, rear);
    return 0;
}
