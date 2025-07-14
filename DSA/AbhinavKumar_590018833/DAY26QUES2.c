#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node ));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void printLinkedList(int n,struct node *head)
    {
        struct node *temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");    
}
void unionLinkedLists(struct node *head1,struct node *head2){
    if(head1==NULL && head2==NULL) return;
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp2->data < temp1->data){
            printf("%d ", temp1->data);
            temp2=temp2->next;
        }
        else if(temp1->data < temp2->data){
            printf("%d ",temp2->data);
            temp1=temp1->next;
        }
        else{
            printf("%d ",temp1->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;

    }
    printf("\n");

     
}
int  main(){
    struct node *head1=createNode(1);
    head1->next=createNode(3);
    head1->next->next=createNode(5);
    head1->next->next->next=createNode(7);
    
    struct node *head2=createNode(2);
    head2->next=createNode(3);
    head2->next->next=createNode(6);
    head2->next->next->next=createNode(8);

    printf("Linked list 1:\n");
    printLinkedList(4,head1);
    
    printf("Linked list 2:\n");
    printLinkedList(4,head2);

    printf("Union of the two linked lists:\n");
    unionLinkedLists(head1, head2);

    return 0;
}