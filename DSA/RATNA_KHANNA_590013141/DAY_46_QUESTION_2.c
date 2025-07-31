#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = 0, rear = -1;
    int n, i, value;
    int even = 0, odd = 0;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
    }

    for (i = front; i <= rear; i++) {
        if (queue[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even: %d, Odd: %d\n", even, odd);

    return 0;
}
