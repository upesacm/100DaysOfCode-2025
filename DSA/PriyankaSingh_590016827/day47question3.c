#include <stdio.h>

int main() {
    int queue[100], n, i;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    if(n == 0) {
        printf("Queue is empty\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Front: %d\n", queue[0]);
    printf("Rear: %d\n", queue[n - 1]);

    return 0;
}
