#include <stdio.h>

int main() {
    int queue[100], counted[100] = {0};
    int n, i, j, count;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Frequency Count:\n");
    for(i = 0; i < n; i++) {
        if(counted[i])
            continue;
        count = 1;
        for(j = i + 1; j < n; j++) {
            if(queue[i] == queue[j]) {
                count++;
                counted[j] = 1;
            }
        }
        printf("%d: %d\n", queue[i], count);
    }

    return 0;
}
