// 1. Sort a K-Sorted Array
// A problem that demonstrates nearly-sorted array optimization and teaches efficient sorting techniques using min-heap for arrays with bounded disorder, leveraging partial order properties for optimal performance.

// Given an array where every element is at most k positions away from its sorted position, sort it using heap-based optimization. This operation is fundamental in partially sorted data processing and bounded disorder optimization where you need to sort nearly-ordered sequences more efficiently than general sorting algorithms. The technique uses min-heap of size k+1 to maintain the smallest elements within the valid range, ensuring each position gets its correct element. This concept is essential in real-time data processing, streaming algorithms, and external sorting where data arrives in nearly-sorted order and requires efficient ordering with minimal memory overhead.

// This teaches nearly-sorted optimization algorithms and bounded heap sorting techniques that are essential for partial order processing and efficient k-sorted array manipulation operations.

// Your task: Implement k-sorted array optimization using min-heap of size k+1 to achieve better than O(n log n) sorting performance on nearly-sorted data.

// Examples
// Input:

// arr = [6, 5, 3, 2, 8, 10, 9], k = 3
// Output:

// [2, 3, 5, 6, 8, 9, 10]
// Input:

// arr = [3, 2, 1, 5, 4, 7, 6, 5], k = 3
// Output:

// [1, 2, 3, 4, 5, 5, 6, 7]


#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;

}

void shiftDown(int arr[], int n, int i){
    int largest=i;
    int left = 2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]) largest=left;
    if(right<n && arr[right]>arr[largest]) largest=right;
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        shiftDown(arr,n,largest);
    }

}
void replaceRoot(int arr[],int n,int newElement){
    if(n<=0) return;
    arr[0]=newElement;
    shiftDown(arr,n,0);

}
void printArray(const char *label,int arr[],int n){
    printf("%s",label);
    for (int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

}
int main(){
    int arr1[]={50,30,20,15,10,8,16};
    int n1=sizeof(int)/sizeof(arr1[0]);
    int newElement1=25;
    printArray("Original array: ",arr1,n1);
    replaceRoot(arr1,n1,newElement1);
    printArray("Array after replacing root: ",arr1,n1);
    return 0;

}