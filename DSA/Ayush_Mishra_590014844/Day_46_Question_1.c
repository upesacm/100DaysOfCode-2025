#include <stdio.h>
#define SIZE 100

int main() {
    int queue[SIZE], front = 0, rear = -1, n, min;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    if (n <= 0) return 1;
    if (n > SIZE) return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    min = queue[front];
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i] < min) min = queue[i];
    }

    printf("Minimum element: %d\n", min);
    return 0;
}
