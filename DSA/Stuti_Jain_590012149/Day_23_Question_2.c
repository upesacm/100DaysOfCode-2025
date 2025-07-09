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

struct Node* removed(struct Node* head) {
    struct Node* curr;
    for(curr=head;curr!=NULL&&curr->next!=NULL;) {
        if(curr->data==curr->next->data) {
            struct Node* temp=curr->next;
            curr->next=temp->next;
            free(temp);
        } else {
            curr=curr->next;
        }
    }
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

    printf("Enter %d sorted node values: ",n);
    struct Node* head=list(n);

    head=removed(head);

    printf("Linked list after removing duplicates:\n");
    printl(head);

    return 0;
}
