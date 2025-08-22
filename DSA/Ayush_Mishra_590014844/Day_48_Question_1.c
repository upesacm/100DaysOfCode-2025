#include <stdio.h>

int main() {
    int n, x, i, j = 0;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    int queue[n], result[n];
    printf("Enter %d queue elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter element to remove: ");
    scanf("%d", &x);

    for (i = 0; i < n; i++) {
        if (queue[i] != x) {
            result[j++] = queue[i];
        }
    }

    printf("Updated queue: ");
    for (i = 0; i < j; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
