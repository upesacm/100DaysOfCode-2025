#include <stdio.h>

void countEvenOdd(int queue[], int size) {
    int even = 0, odd = 0;
    for (int i = 0; i < size; i++) {
        if (queue[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    printf("Even: %d, Odd: %d\n", even, odd);
}

int main() {
    int queue[100], size;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }

    countEvenOdd(queue, size);
    return 0;
}
