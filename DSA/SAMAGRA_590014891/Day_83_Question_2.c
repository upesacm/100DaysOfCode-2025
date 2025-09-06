#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void serializeHelper(Node* root, char* buf) {
    if(!root) return;
    char temp[20];
    sprintf(temp,"%d,",root->val);
    strcat(buf,temp);
    serializeHelper(root->left, buf);
    serializeHelper(root->right, buf);
}

char* serialize(Node* root) {
    char* buf = (char*)malloc(1000);
    buf[0]='\0';
    serializeHelper(root, buf);
    if(strlen(buf)>0) buf[strlen(buf)-1]='\0';
    return buf;
}

Node* buildBST(int* preorder, int* idx, int min, int max, int n) {
    if(*idx>=n) return NULL;
    int val = preorder[*idx];
    if(val<min || val>max) return NULL;
    (*idx)++;
    Node* root = newNode(val);
    root->left = buildBST(preorder, idx, min, val, n);
    root->right = buildBST(preorder, idx, val, max, n);
    return root;
}

Node* deserialize(char* data) {
    if(strlen(data)==0) return NULL;
    int arr[100], n=0;
    char* tok = strtok(data,",");
    while(tok) {
        arr[n++] = atoi(tok);
        tok = strtok(NULL,",");
    }
    int idx=0;
    return buildBST(arr,&idx,-10000,10000,n);
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int main() {
    Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    char* ser = serialize(root);
    printf("Serialized: %s\n", ser);

    Node* des = deserialize(ser);
    printf("Inorder: ");
    inorder(des);
    printf("\n");
    return 0;
}
