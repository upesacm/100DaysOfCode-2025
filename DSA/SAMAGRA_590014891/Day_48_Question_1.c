#include <stdio.h>

int main() {
    int queue[100], n, x, i, newQueue[100], newSize = 0;

    printf("Enter size of queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter element to remove: ");
    scanf("%d", &x);

    for(i = 0; i < n; i++) {
        if(queue[i] != x)
            newQueue[newSize++] = queue[i];
    }

    printf("Updated Queue: ");
    for(i = 0; i < newSize; i++)
        printf("%d ", newQueue[i]);

    return 0;
}
