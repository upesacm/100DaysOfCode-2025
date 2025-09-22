#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n, k;

int maxInWindow(int start, int end) {
    int max = arr[start];
    for (int i = start+1; i <= end; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void slidingWindowMax() {
    for (int i = 0; i <= n-k; i++) {
        int maxVal = maxInWindow(i, i+k-1);
        printf("%d ", maxVal);
    }
    printf("\n");
}

int main() {
    int temp[] = {1,3,-1,-3,5,3,6,7};
    n = sizeof(temp)/sizeof(temp[0]);
    k = 3;
    for (int i = 0; i < n; i++) arr[i] = temp[i];

    slidingWindowMax();
    return 0;
}
