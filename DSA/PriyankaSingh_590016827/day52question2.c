#include <stdio.h>

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the difference value k: ");
    scanf("%d", &k);

    printf("Pairs with difference %d:\n", k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && arr[i] - arr[j] == k)
                printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }

    return 0;
}
