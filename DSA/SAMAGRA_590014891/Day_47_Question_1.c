#include <stdio.h>

#define MAX 100

void insertRear(int queue[], int *rear, int element) {
    if (*rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    (*rear)++;
    queue[*rear] = element;
}

void printQueue(int queue[], int front, int rear) {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[MAX], front = 0, rear = -1;
    int n, element;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertRear(queue, &rear, x);
    }

    printf("Enter element to insert at rear: ");
    scanf("%d", &element);
    insertRear(queue, &rear, element);

    printf("Updated Queue: ");
    printQueue(queue, front, rear);
    return 0;
}
