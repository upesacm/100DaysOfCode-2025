#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int getk(struct Node* head, int k){
    int count = 0, i;
    struct Node* temp = head;

    for(i = 0; temp != NULL; i++){
        count++;
        temp = temp->next;
    }

    if(k > count){
        return -1;
    }

    int target = count - k;
    temp = head;

    for(i = 0; i < target; i++){
        temp = temp->next;
    }

    if(temp != NULL){
        return temp->data;
    }else{
        return -1;
    }
}

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* createL(int n){
    int val, i;
    struct Node *head = NULL, *tail = NULL;

    for(i = 0; i < n; i++){
        scanf("%d", &val);
        struct Node* node = newNode(val);

        if(head == NULL){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

int main(){
    int n, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values: ", n);
    struct Node* head = createL(n);

    printf("Enter k: ");
    scanf("%d", &k);

    int result = getk(head, k);
    printf("%d\n", result);

    return 0;
}
