#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

void heapify(int arr[], int n, int i) {
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]<arr[smallest]) smallest=l;
    if(r<n && arr[r]<arr[smallest]) smallest=r;
    if(smallest!=i){ swap(&arr[i],&arr[smallest]); heapify(arr,n,smallest);}
}

void buildMinHeap(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

int kthLargestSum(int arr[], int n, int k) {
    int prefix[n+1]; prefix[0]=0;
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+arr[i-1];

    int heap[k]; int size=0;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            int sum=prefix[j]-prefix[i-1];
            if(size<k){ heap[size++]=sum; if(size==k) buildMinHeap(heap,k);}
            else if(sum>heap[0]) { heap[0]=sum; heapify(heap,k,0);}
        }
    }
    return heap[0];
}

int main() {
    int arr1[] = {10,-10,20,-40};
    printf("3rd largest sum: %d\n", kthLargestSum(arr1,4,3)); // Output: 10

    int arr2[] = {1,2,3};
    printf("2nd largest sum: %d\n", kthLargestSum(arr2,3,2)); // Output: 5
    return 0;
}
