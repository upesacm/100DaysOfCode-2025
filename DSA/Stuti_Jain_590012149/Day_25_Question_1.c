#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int v;
    struct Node* n;
};

struct Node* new(int v){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->v=v;
    n->n=NULL;
    return n;
}

struct Node* rev(struct Node* h){
    struct Node* p=NULL;
    while(h){
        struct Node* x=h->n;
        h->n=p;
        p=h;
        h=x;
    }
    return p;
}

bool isPal(struct Node* h){
    if(!h || !h->n)return true;
    struct Node* s=h;
    struct Node* f=h;
    while(f && f->n){
        s=s->n;
        f=f->n->n;
    }
    struct Node* h2=rev(s);
    struct Node* h1=h;
    while(h2){
        if(h1->v != h2->v)return false;
        h1=h1->n;
        h2=h2->n;
    }
    return true;
}

int main(){
    int n,x;
    struct Node *h=NULL,*t=NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements:\n",n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        struct Node* tmp=new(x);
        if(!h)h=t=tmp;
        else{t->n=tmp; t=tmp;}
    }

    if(isPal(h)){
        printf("true\n");
    }else{
        printf("false\n");
    }

    return 0;
}
