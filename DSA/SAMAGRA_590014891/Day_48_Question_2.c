#include <stdio.h>

int main() {
    int queue[100], visited[100] = {0}, n, i, j;

    printf("Enter size of queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Frequency Distribution:\n");
    for(i = 0; i < n; i++) {
        if(visited[i])
            continue;
        int count = 1;
        for(j = i + 1; j < n; j++) {
            if(queue[i] == queue[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d: %d\n", queue[i], count);
    }

    return 0;
}
