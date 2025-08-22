#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

void heapify(int arr[],int n,int i){
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]<arr[smallest]) smallest=l;
    if(r<n && arr[r]<arr[smallest]) smallest=r;
    if(smallest!=i){swap(&arr[i],&arr[smallest]);heapify(arr,n,smallest);}
}

void insertHeap(int heap[],int *n,int val,int k){
    if(*n<k){
        heap[(*n)++]=val;
        for(int i=*n/2-1;i>=0;i--) heapify(heap,*n,i);
    }else if(val>heap[0]){
        heap[0]=val;
        heapify(heap,*n,0);
    }
}

int main(){
    int n,k;
      printf("enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
      printf("enter the elements\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
      printf("enter value of k\n");
    scanf("%d",&k);

    int prefix[n+1]; prefix[0]=0;
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+arr[i-1];

    int heap[100000],heapSize=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            int sum=prefix[i]-prefix[j];
            insertHeap(heap,&heapSize,sum,k);
        }
    }

    printf("Output:\n%d\n",heap[0]);
    return 0;
}
