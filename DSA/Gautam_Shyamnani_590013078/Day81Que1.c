#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) return createnode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
int RangeSum(struct node *root,int L,int R){
    int sum=0;
    if(root==NULL) return 0;
    if(root->data>=L && root->data<=R){
        sum+=root->data;
    }
    sum+=RangeSum(root->left,L,R);
    sum+=RangeSum(root->right,L,R);
    return sum;
}


int main() {
    int n, val;
    struct node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter the L and R value for the given BST: ");
    int L,R;
    scanf("%d",&L);
    scanf("%d",&R);
    int sum=RangeSum(root,L,R);
    printf("TOTAL SUM IS : %d",sum);
    return 0;
}
