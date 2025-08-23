#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter number of trains: ");
    scanf("%d", &n);

    int arr[n], dep[n];
    printf("Enter arrival times:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter departure times:\n");
    for(int i=0;i<n;i++) scanf("%d",&dep[i]);

    qsort(arr, n, sizeof(int), compare);
    qsort(dep, n, sizeof(int), compare);

    int platforms=1, result=1, i=1, j=0;
    while(i<n && j<n) {
        if(arr[i]<=dep[j]) {
            platforms++;
            if(platforms>result) result=platforms;
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    printf("Minimum number of platforms required: %d\n", result);
    return 0;
}
