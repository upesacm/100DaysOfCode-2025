#include <stdio.h>

int main() {
    int n;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int h[n];
    printf("enter elements\n");
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    int l = 0, r = n - 1, max = 0;
    while(l < r) {
        int height = h[l] < h[r] ? h[l] : h[r];
        int area = height * (r - l);
        if(area > max) max = area;
        if(h[l] < h[r]) l++;
        else r--;
    }
    printf("%d\n", max);
    return 0;
}
