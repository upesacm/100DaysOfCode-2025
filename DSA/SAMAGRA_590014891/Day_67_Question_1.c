#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char ab[50], ba[50];
    sprintf(ab, "%s%s", *(char **)a, *(char **)b);
    sprintf(ba, "%s%s", *(char **)b, *(char **)a);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    char **arr = malloc(numsSize * sizeof(char*));
    for(int i=0;i<numsSize;i++) {
        arr[i] = malloc(20);
        sprintf(arr[i], "%d", nums[i]);
    }

    qsort(arr, numsSize, sizeof(char*), compare);

    char *res = malloc(1000);
    res[0] = '\0';
    for(int i=0;i<numsSize;i++) strcat(res, arr[i]);

    if(res[0]=='0') return "0";
    return res;
}

int main() {
    int nums1[] = {10, 2};
    int nums2[] = {3,30,34,5,9};

    printf("%s\n", largestNumber(nums1, 2));  
    printf("%s\n", largestNumber(nums2, 5));  

    return 0;
}
