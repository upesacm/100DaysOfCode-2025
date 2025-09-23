#include <stdio.h>

#define MAX 1000
int stack[MAX], top = -1;

void push(int val) { stack[++top] = val; }
void pop() { if (top >= 0) top--; }
int peek() { return stack[top]; }

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    for (int i = 0; i <= n - k; i++) {
        top = -1;
        for (int j = i; j < i + k; j++) {
            while (top >= 0 && peek() < arr[j]) pop();
            push(arr[j]);
        }
        printf("%d ", peek());
    }
    printf("\n");
    return 0;
}
