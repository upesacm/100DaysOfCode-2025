#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createN(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

struct Node* end(struct Node* head,int data){
    struct Node* newNode=createN(data);
    if(head==NULL){
        return newNode;
    }
    struct Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    return head;
}

void printLL(struct Node* head){
    while(head!=NULL){
        printf("%d",head->data);
        if(head->next!=NULL)printf(" -> ");
        head=head->next;
    }
    printf(" -> NULL\n");
}

struct Node* position(struct Node* head,int x){
    if(head==NULL)return NULL;
    if(x==1){
        struct Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct Node* curr=head;
    for(int i=1; i<x-1 && curr!=NULL; i++)
        curr=curr->next;
    if(curr==NULL||curr->next==NULL)return head;
    struct Node* temp=curr->next;
    curr->next=temp->next;
    free(temp);
    return head;
}

int main(){
    struct Node* head=NULL;
    int n,x,val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter data for the nodes: ");
        scanf("%d", &val);
        head=end(head, val);
    }
    printf("Enter position to delete: ");
    scanf("%d", &x);
    head=position(head, x);
    printf("\n");
    printLL(head);
    return 0;
}
