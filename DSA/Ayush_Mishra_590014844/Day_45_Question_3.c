#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    int queue[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    int max = queue[0];
    for (int i = 1; i < n; i++) {
        if (queue[i] > max)
            max = queue[i];
    }

    printf("Maximum element: %d\n", max);
    return 0;
}
