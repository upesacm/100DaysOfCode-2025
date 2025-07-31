#include <stdio.h>
#define SIZE 100

int main() {
    int queue[SIZE], front = 0, rear = -1, n;
    int even = 0, odd = 0;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    if (n <= 0) return 1;
    if (n > SIZE) return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        queue[++rear] = val;
        if (val % 2 == 0) even++;
        else odd++;
    }

    printf("Even: %d, Odd: %d\n", even, odd);
    return 0;
}
