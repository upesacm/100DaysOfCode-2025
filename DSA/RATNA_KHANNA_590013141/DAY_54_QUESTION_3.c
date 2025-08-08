#include <stdio.h>

int main() {
    int n, k;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
     printf("enter value of k \n");
    scanf("%d", &k);
    if(k <= 1) {
        printf("0\n");
        return 0;
    }
    long long prod = 1;
    int left = 0;
    long long count = 0;
    for(int right = 0; right < n; right++) {
        prod *= arr[right];
        while(prod >= k) {
            prod /= arr[left];
            left++;
        }
        count += (right - left + 1);
    }
    printf("%lld\n", count);
    return 0;
}
