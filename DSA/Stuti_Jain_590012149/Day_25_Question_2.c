#include<stdio.h>
#include<stdlib.h>
struct Node{
    int d;
    struct Node* n;
};

struct Node* new(int d){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->d=d;
    t->n=NULL;
    return t;
}

struct Node* add(struct Node* h, int d){
    struct Node* t=new(d);
    if(!h)return t;
    struct Node* c=h;
    while(c->n)c=c->n;
    c->n=t;
    return h;
}

void print(struct Node* h){
    while(h){
        printf("%d", h->d);
        if(h->n)printf("->");
        h=h->n;
    }
    printf("\n");
}

struct Node* inter(struct Node* a, struct Node* b){
    struct Node* r=NULL,*t=NULL;
    while(a && b){
        if(a->d==b->d){
            struct Node* n=new(a->d);
            if(!r){r=t=n;}
            else{t->n=n; t=n;}
            a=a->n;
            b=b->n;
        }
        else if(a->d<b->d)a=a->n;
        else b=b->n;
    }
    return r;
}

int main(){
    struct Node *a=NULL,*b=NULL;
    int n,m,x;
    printf("Enter number of elements in List 1: ");
    scanf("%d",&n);
    printf("Enter the elements:\n",n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        a=add(a,x);
    }
    printf("Enter number of elements in List 2: ");
    scanf("%d",&m);
    printf("Enter the elements:\n",m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        b=add(b,x);
    }
    struct Node* r=inter(a,b);
    printf("Intersection: ");
    print(r);
    return 0;
}
