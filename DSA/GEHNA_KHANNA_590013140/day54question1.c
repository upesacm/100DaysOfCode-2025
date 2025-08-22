#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ((int)a - (int)b);
}

int main() {
    int n, i, l, r;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    int target=0;
    qsort(arr, n, sizeof(int), cmp);
    int found = 0;
    for(i = 0; i < n - 2; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        l = i + 1;
        r = n - 1;
        while(l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == target) {
                printf("[%d, %d, %d]\n", arr[i], arr[l], arr[r]);
                found = 1;
                while(l < r && arr[l] == arr[l + 1]) l++;
                while(l < r && arr[r] == arr[r - 1]) r--;
                l++;
                r--;
            } else if(sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    if(!found) printf("[]\n");
    return 0;
}
