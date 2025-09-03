#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *ancestor_node(struct node *p1,int n1,int n2){
    while(p1!=NULL){
    if(n1>p1->data && n2>p1->data){
        p1=p1->right;
    }else if(n1<p1->data && n2<p1->data){
        p1=p1->left;
    }else{
        return p1;
    }
}
return NULL;
}
int main(){
    struct node *p1=createnode(6);
    struct node *p2=createnode(2);
    struct node *p3=createnode(8);
    struct node *p4=createnode(0);
    struct node *p5=createnode(4);
    struct node *p6=createnode(7);
    struct node *p7=createnode(9);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=p6;
    p3->right=p7;
    int node1=6,node2=8;
    struct node *p=ancestor_node(p1,node1,node2);
    if(p!=NULL){
        printf("%d is the ancestor node.",p->data);
    }else{
        printf("Ancestor node does not exist");
    }
    return 0;
}
