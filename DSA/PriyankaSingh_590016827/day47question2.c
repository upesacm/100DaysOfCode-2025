#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX], n, i, insert;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter element to insert at front: ");
    scanf("%d", &insert);

    if(n < MAX) {
        for(i = n; i > 0; i--)
            queue[i] = queue[i - 1];
        queue[0] = insert;
        n++;
    }

    printf("Updated Queue: ");
    for(i = 0; i < n; i++)
        printf("%d ", queue[i]);

    return 0;
}
