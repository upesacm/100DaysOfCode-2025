#include <stdio.h>

int main() {
    int n;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_count = 0, count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            count++;
            if(count > max_count) {
                max_count = count;
            }
        } else {
            count = 0;
        }
    }

    printf("output-%d\n", max_count);
    return 0;
}
