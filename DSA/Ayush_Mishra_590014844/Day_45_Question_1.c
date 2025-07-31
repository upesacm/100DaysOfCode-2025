#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    int queue[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += queue[i];

    printf("Sum of elements: %d\n", sum);
    return 0;
}
