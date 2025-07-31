#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear < MAX - 1) queue[++rear] = x;
}

void countEvenOdd(int* even, int* odd) {
    *even = 0; *odd = 0;
    for (int i = front; i <= rear; i++)
        if (queue[i] % 2 == 0) (*even)++; else (*odd)++;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    int even, odd;
    countEvenOdd(&even, &odd);
    printf("Even: %d, Odd: %d\n", even, odd);
    return 0;
}
