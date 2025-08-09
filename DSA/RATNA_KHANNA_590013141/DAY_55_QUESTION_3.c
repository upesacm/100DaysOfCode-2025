#include <stdio.h>
#include <stdlib.h>

struct Node {int key,val;struct Node*next;};

int get(struct Node**map,int key,int*found){
    int idx=abs(key)%1000;
    struct Node*cur=map[idx];
    while(cur){if(cur->key==key){*found=1;return cur->val;}cur=cur->next;}
    *found=0;return 0;
}

void put(struct Node**map,int key,int val){
    int idx=abs(key)%1000;
    struct Node*cur=map[idx];
    while(cur){if(cur->key==key){cur->val+=val;return;}cur=cur->next;}
    struct Node*node=malloc(sizeof(struct Node));
    node->key=key;node->val=val;node->next=map[idx];map[idx]=node;
}

int main(){
    int n,goal;
    printf("enter number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements\n");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    printf("enter value of goal\n");
    scanf("%d",&goal);
    struct Node*map[1000]={0};
    put(map,0,1);
    int sum=0,count=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int found;
        count+=get(map,sum-goal,&found);
        put(map,sum,1);
    }
    printf("output-%d",count);
}
