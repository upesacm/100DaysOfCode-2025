#include <stdio.h>

int main() {
    int n, i, element;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    int queue[n + 1];
    printf("Enter %d elements:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &element);

    queue[0] = element;
    printf("Updated queue: ");
    for (i = 0; i <= n; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}
