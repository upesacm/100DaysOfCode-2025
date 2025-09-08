#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node *node;
    int hd;
    struct QNode *next;
} QNode;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

typedef struct Map {
    int hd;
    int arr[100];
    int size;
    struct Map* next;
} Map;

Map* addToMap(Map* head, int hd, int val) {
    Map* temp = head;
    while(temp) {
        if(temp->hd == hd) {
            temp->arr[temp->size++] = val;
            return head;
        }
        temp = temp->next;
    }
    Map* newM = (Map*)malloc(sizeof(Map));
    newM->hd = hd;
    newM->arr[0] = val;
    newM->size = 1;
    newM->next = head;
    return newM;
}

void verticalOrder(Node* root) {
    if(!root) return;
    QNode* front = NULL, *rear = NULL;
    Map* map = NULL;
    QNode* q = (QNode*)malloc(sizeof(QNode));
    q->node = root; q->hd = 0; q->next = NULL;
    front = rear = q;

    while(front) {
        QNode* temp = front;
        front = front->next;
        if(!front) rear = NULL;

        Node* n = temp->node;
        int hd = temp->hd;
        map = addToMap(map, hd, n->val);

        if(n->left) {
            QNode* l = (QNode*)malloc(sizeof(QNode));
            l->node = n->left; l->hd = hd-1; l->next = NULL;
            if(!rear) front = rear = l; else {rear->next = l; rear = l;}
        }
        if(n->right) {
            QNode* r = (QNode*)malloc(sizeof(QNode));
            r->node = n->right; r->hd = hd+1; r->next = NULL;
            if(!rear) front = rear = r; else {rear->next = r; rear = r;}
        }
        free(temp);
    }
    for(int i=-10;i<=10;i++) {
        Map* t = map;
        while(t) {
            if(t->hd==i) {
                printf("[");
                for(int j=0;j<t->size;j++) {
                    printf("%d",t->arr[j]);
                    if(j<t->size-1) printf(",");
                }
                printf("] ");
            }
            t=t->next;
        }
    }
    printf("\n");
}

int main() {
    Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    verticalOrder(root);
    return 0;
}
