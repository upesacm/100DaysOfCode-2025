#include <stdio.h>

int main() {
    int queue[100], newQueue[100];
    int n, i, x, j = 0;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the element to remove: ");
    scanf("%d", &x);

    for(i = 0; i < n; i++) {
        if(queue[i] != x)
            newQueue[j++] = queue[i];
    }

    printf("Updated Queue: ");
    for(i = 0; i < j; i++)
        printf("%d ", newQueue[i]);

    return 0;
}
