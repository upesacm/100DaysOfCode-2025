#include <stdio.h>

#define MAX 100

void findFrontRear(int queue[], int front, int rear) {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front: %d, Rear: %d\n", queue[front], queue[rear]);
}

int main() {
    int queue[MAX], front = 0, rear = -1;
    int n;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    
    if (n == 0) {
        findFrontRear(queue, front, rear);
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        rear++;
        scanf("%d", &queue[rear]);
    }

    findFrontRear(queue, front, rear);
    return 0;
}
