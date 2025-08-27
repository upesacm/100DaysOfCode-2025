#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l]<arr[smallest]) smallest = l;
    if(r<n && arr[r]<arr[smallest]) smallest = r;
    if(smallest!=i) {
        int t=arr[i]; arr[i]=arr[smallest]; arr[smallest]=t;
        heapify(arr,n,smallest);
    }
}

int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0]=arr[*n-1];
    (*n)--;
    heapify(arr,*n,0);
    return root;
}

void insertHeap(int arr[], int *n, int val) {
    arr[*n]=val;
    int i=*n; (*n)++;
    while(i!=0 && arr[(i-1)/2]>arr[i]) {
        int t=arr[i]; arr[i]=arr[(i-1)/2]; arr[(i-1)/2]=t;
        i=(i-1)/2;
    }
}

int minCost(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    int cost=0;
    while(n>1) {
        int a=extractMin(arr,&n);
        int b=extractMin(arr,&n);
        cost+=a+b;
        insertHeap(arr,&n,a+b);
    }
    return cost;
}

int main() {
    int arr1[]={4,3,2,6};
    int arr2[]={1,2,3,4,5};
    printf("%d\n", minCost(arr1,4)); 
    printf("%d\n", minCost(arr2,5)); 
    return 0;
}
