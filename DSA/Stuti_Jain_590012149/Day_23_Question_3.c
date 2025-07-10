#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* node2(int data) {
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}

struct Node* list(int n) {
    int val,i;
    struct Node *head=NULL,*tail=NULL;
    for(i=0;i<n;i++) {
        scanf("%d",&val);
        struct Node* node=node2(val);
        if(head==NULL) {
            head=node;
            tail=node;
        } else {
            tail->next=node;
            tail=node;
        }
    }
    return head;
}

struct Node* mid(struct Node* head) {
    if(head==NULL||head->next==NULL) {
        free(head);
        return NULL;
    }

    int count=0,i;
    struct Node* temp=head;
    for(;temp!=NULL;temp=temp->next) {
        count++;
    }

    int pos=count/2;
    temp=head;
    for(i=0;i<pos-1;i++) {
        temp=temp->next;
    }

    struct Node* del=temp->next;
    temp->next=del->next;
    free(del);

    return head;
}

void printl(struct Node* head) {
    struct Node* temp;
    for(temp=head;temp!=NULL;temp=temp->next) {
        printf("%d",temp->data);
        if(temp->next!=NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter %d node values: ",n);
    struct Node* head=list(n);

    head=mid(head);

    printf("Linked list after deleting middle node:\n");
    printl(head);

    return 0;
}
