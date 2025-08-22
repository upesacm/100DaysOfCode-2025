#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
void heapify(int arr[],int n,int i){
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<n&&arr[l]<arr[smallest])smallest=l;
    if(r<n&&arr[r]<arr[smallest])smallest=r;
    if(smallest!=i){swap(&arr[i],&arr[smallest]);heapify(arr,n,smallest);}
}
int extractMin(int arr[],int *n){
    int root=arr[0];arr[0]=arr[--(*n)];heapify(arr,*n,0);return root;
}
void insertHeap(int arr[],int *n,int key){
    int i=(*n)++;arr[i]=key;
    while(i&&arr[(i-1)/2]>arr[i]){swap(&arr[i],&arr[(i-1)/2]);i=(i-1)/2;}
}
int main(){
    char ch;
    int arr[1000],n=0;
    printf("Input:\n");
    printf("[");
    scanf(" [");
    while(1){
        int x;
        if(scanf("%d",&x)!=1)break;
        arr[n++]=x;
        printf("%d",x);
        scanf("%c",&ch);
        if(ch==']'){printf("]");break;}
        else if(ch==','){printf(", ");} 
    }
    printf("\n");
    for(int i=n/2-1;i>=0;i--)heapify(arr,n,i);
    int cost=0;
    while(n>1){
        int x=extractMin(arr,&n);
        int y=extractMin(arr,&n);
        cost+=x+y;
        insertHeap(arr,&n,x+y);
    }
    printf("Output:\n%d\n",cost);
    return 0;
}
