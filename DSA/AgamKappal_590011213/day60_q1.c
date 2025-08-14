#include <stdio.h>

void swap(int *a, int *b){int t=*a;*a=*b;*b=t;}

void minHeapify(int heap[], int n, int i){
    int smallest=i, l=2*i+1, r=2*i+2;
    if(l<n && heap[l]<heap[smallest]) smallest=l;
    if(r<n && heap[r]<heap[smallest]) smallest=r;
    if(smallest!=i){swap(&heap[i],&heap[smallest]);minHeapify(heap,n,smallest);}
}

void buildMinHeap(int heap[], int n){
    for(int i=n/2-1;i>=0;i--) minHeapify(heap,n,i);
}

int extractMin(int heap[], int *n){
    int root=heap[0];
    heap[0]=heap[*n-1];
    (*n)--;
    if(*n>0) minHeapify(heap,*n,0);
    return root;
}

void insertMinHeap(int heap[], int *n, int val){
    int i=*n; heap[i]=val; (*n)++;
    while(i>0 && heap[(i-1)/2]>heap[i]){swap(&heap[i],&heap[(i-1)/2]); i=(i-1)/2;}
}

void sortKSorted(int arr[], int n, int k){
    int size=k+1; if(size>n) size=n;
    int heap[100000];
    int heapSize=0;
    for(int i=0;i<size;i++){heap[heapSize++]=arr[i];}
    buildMinHeap(heap,heapSize);
    int idx=0;
    for(int i=size;i<n;i++){
        arr[idx++]=extractMin(heap,&heapSize);
        insertMinHeap(heap,&heapSize,arr[i]);
    }
    while(heapSize>0) arr[idx++]=extractMin(heap,&heapSize);
}

int main(){
    int arr1[]={6,5,3,2,8,10,9}; int n1=7; int k1=3;
    sortKSorted(arr1,n1,k1);
    for(int i=0;i<n1;i++) printf("%d ",arr1[i]);
    printf("\n");
    int arr2[]={3,2,1,5,4,7,6,5}; int n2=8; int k2=3;
    sortKSorted(arr2,n2,k2);
    for(int i=0;i<n2;i++) printf("%d ",arr2[i]);
    return 0;
}
