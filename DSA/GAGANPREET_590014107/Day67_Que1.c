#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    char strA[20], strB[20];
    sprintf(strA, "%d", *(int*)a);
    sprintf(strB, "%d", *(int*)b);
    char concatAB[40], concatBA[40];
    strcpy(concatAB, strA);
    strcat(concatAB, strB);
    strcpy(concatBA, strB);
    strcat(concatBA, strA);
    return strcmp(concatBA, concatAB);
}

char* largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    char* result = (char*)malloc(numsSize * 20 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        char str[20];
        sprintf(str, "%d", nums[i]);
        strcat(result, str);
    }
    while (result[0] == '0' && result[1] != '\0') {
        for (int i = 0; i < strlen(result); i++) {
            result[i] = result[i + 1];
        }
    }
    return result;
}

int main() {
    int nums1[] = {10, 2};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("%s\n", largestNumber(nums1, numsSize1));

    int nums2[] = {3, 30, 34, 5, 9};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%s\n", largestNumber(nums2, numsSize2));

    return 0;
}
