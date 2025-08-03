#include<stdio.h>
#include<stdlib.h>
int* nextGreaterElement(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        while (top != -1 && nums[i] > nums[stack[top]]) {
            result[stack[top]] = nums[i];
            top--;
        }
        stack[++top] = i;
    }
    *returnSize = numsSize;
    free(stack);
    return result;
}
int main() {
    int input1[] = {4, 5, 2, 25};
    int input2[] = {13, 7, 6, 12};
    int size1 = sizeof(input1) / sizeof(input1[0]);
    int size2 = sizeof(input2) / sizeof(input2[0]);
    int returnSize;
    int* output1 = nextGreaterElement(input1, size1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", output1[i]);
    }
    printf("\n");
    int* output2 = nextGreaterElement(input2, size2, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", output2[i]);
    }
    printf("\n");
    free(output1);
    free(output2);
    return 0;
}
