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

struct Node* deleteMN(struct Node* head,int m,int n){
    struct Node* curr=head;
    struct Node* temp;
    while(curr){
        for(int i=1; i<m && curr!=NULL; i++)
            curr=curr->next;
        if(curr==NULL)break;
        temp=curr->next;
        for(int i=1; i<=n && temp!=NULL; i++){
            struct Node* del=temp;
            temp=temp->next;
            free(del);
        }
        curr->next=temp;
        curr=temp;
    }
    return head;
}

int main(){
    struct Node* head=NULL;
    int n,x,m,del;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter data for the nodes: ");
        scanf("%d", &x);
        head=end(head,x);
    }
    printf("Enter nodes to skip: ");
    scanf("%d", &m);
    printf("Enter nodes to delete: ");
    scanf("%d", &del);
    head=deleteMN(head, m, del);
    printf("\n");
    printLL(head);
    return 0;
}
