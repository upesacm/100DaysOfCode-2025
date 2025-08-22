#include <stdio.h>
#define SIZE 100

void countEvenOdd(int queue[], int front, int rear, int* even, int* odd) {
    *even = *odd = 0;
    for (int i = front; i <= rear; i++) {
        if (queue[i] % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
}

int main() {
    int queue[SIZE] = {1, 2, 3, 4, 5};
    int front = 0, rear = 4;
    int evenCount, oddCount;

    countEvenOdd(queue, front, rear, &evenCount, &oddCount);

    printf("Even: %d, Odd: %d\n", evenCount, oddCount);
    return 0;
}
