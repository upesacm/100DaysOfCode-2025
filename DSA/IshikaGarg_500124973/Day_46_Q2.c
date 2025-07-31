#include <stdio.h>
#define SIZE 100

int queue2[SIZE], front2 = -1, rear2 = -1;

void enqueue2(int val) {
    if (rear2 == SIZE - 1)
        printf("Queue is full\n");
    else {
        if (front2 == -1)
            front2 = 0;
        queue2[++rear2] = val;
    }
}

void displayQueue2() {
    for (int i = front2; i <= rear2; i++)
        printf("%d ", queue2[i]);
    printf("\n");
}

// Function to count even and odd
void countEvenOdd() {
    if (front2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    int even = 0, odd = 0;
    for (int i = front2; i <= rear2; i++) {
        if (queue2[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even: %d, Odd: %d\n", even, odd);
}

int main() {
    // Input: [1, 2, 3, 4, 5]
    enqueue2(1);
    enqueue2(2);
    enqueue2(3);
    enqueue2(4);
    enqueue2(5);

    printf("Queue elements: ");
    displayQueue2();

    countEvenOdd();

    return 0;
}

