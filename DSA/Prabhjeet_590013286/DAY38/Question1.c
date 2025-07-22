 #include <stdio.h>

void func(int arr[], int n) {
    int stack[n], res[n], top = -1;
    for(int i = n-1; i >= 0; i--) {
        while(top != -1 && stack[top] <= arr[i]) top--;
        if(top == -1) res[i] = -1;
        else res[i] = stack[top];
        stack[++top] = arr[i];
    }
    for(int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
}

int main() {
    int n, arr[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    func(arr, n);
    return 0;
}
