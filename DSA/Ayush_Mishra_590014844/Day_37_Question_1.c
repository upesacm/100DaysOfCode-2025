#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX], sorted[MAX], top = -1, stop = -1, n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }

    while(top != -1) {
        int temp = stack[top--];
        while(stop != -1 && sorted[stop] > temp) {
            stack[++top] = sorted[stop--];
        }
        sorted[++stop] = temp;
    }

    for(i = stop; i >= 0; i--)
        printf("%d ", sorted[i]);

    return 0;
}
