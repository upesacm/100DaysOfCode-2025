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

struct Node* reverse(struct Node* head){
    struct Node* prev=NULL;
    struct Node* curr=head;
    struct Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    struct Node* head=NULL;
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter data for the nodes: ");
        scanf("%d", &x);
        head=end(head, x);
    }
    head=reverse(head);
    printf("Reversed List:\n");
    printLL(head);
    return 0;
}
