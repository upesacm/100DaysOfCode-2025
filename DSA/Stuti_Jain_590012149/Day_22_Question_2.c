#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int freq(struct Node* head, int key){
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            count++;
        }
        temp=temp->next;
    }
    return count;
}

int main(){
    int n, i, value, key;
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
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

    printf("Key: ");
    scanf("%d", &key);

    int result=freq(head, key);
    printf("Frequency: %d\n", result);

    return 0;
}
