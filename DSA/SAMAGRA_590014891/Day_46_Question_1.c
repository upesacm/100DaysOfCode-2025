#include <stdio.h>
#include <limits.h>

int findMin(int queue[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (queue[i] < min)
            min = queue[i];
    }
    return min;
}

int main() {
    int queue[100], size;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Minimum element: %d\n", findMin(queue, size));
    return 0;
}
