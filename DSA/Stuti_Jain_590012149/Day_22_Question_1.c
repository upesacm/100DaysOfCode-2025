#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void findMiddle(struct Node* head){
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int mid=count/2;
    temp=head;
    for(int i=0;i<mid;i++){
        temp=temp->next;
    }
    printf("Middle node is: %d\n", temp->data);
}

int main(){
    int n,i,value;
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    findMiddle(head);
    return 0;
}
