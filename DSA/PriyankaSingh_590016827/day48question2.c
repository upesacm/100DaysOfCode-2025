#include <stdio.h>

int main() {
    int queue[100];
    int n, i, j, unique = 1;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(queue[i] == queue[j]) {
                unique = 0;
                break;
            }
        }
        if(!unique)
            break;
    }

    if(unique)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
