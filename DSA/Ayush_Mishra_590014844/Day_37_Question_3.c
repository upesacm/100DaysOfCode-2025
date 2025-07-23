#include <stdio.h>
#define MAX 100

void delete_middle(int stack[], int index, int mid) {
    if(index == mid)
        return;
    int val = stack[index];
    delete_middle(stack, index + 1, mid);
    stack[index - (index > mid)] = val;
}

int main() {
    int stack[MAX], n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &stack[i]);

    int mid = n / 2;
    delete_middle(stack, 0, mid);

    for(int i = 0; i < n - 1; i++)
        printf("%d ", stack[i]);

    return 0;
}
