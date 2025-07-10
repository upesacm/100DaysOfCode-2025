#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* addTwoNumbers(Node* num1, Node* num2) {
    Node* dummyHead = createNode(0);
    Node* current = dummyHead;
    int carry = 0;
    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }   
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }
    Node* resultHead = dummyHead->next;
    free(dummyHead);
    while (resultHead != NULL && resultHead->data == 0) {
        Node* temp = resultHead;
        resultHead = resultHead->next;
        free(temp);
    }
    return resultHead == NULL ? createNode(0) : resultHead; // Return 0 if the result is empty
}
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}
int main() {
    Node* num1 = createNode(4);
    num1->next = createNode(5);
    Node* num2 = createNode(3);
    num2->next = createNode(4);
    num2->next->next = createNode(5);
    printf("Number 1: ");
    printLinkedList(num1);
    printf("Number 2: ");
    printLinkedList(num2);
    Node* sum = addTwoNumbers(num1, num2);
    printf("Sum: ");
    printLinkedList(sum);
    Node* num3 = createNode(0);
    num3->next = createNode(0);
    num3->next->next = createNode(6);
    num3->next->next->next = createNode(3);
    Node* num4 = createNode(0);
    num4->next = createNode(7);
    printf("Number 3: ");
    printLinkedList(num3);
    printf("Number 4: ");
    printLinkedList(num4);
    Node* sum2 = addTwoNumbers(num3, num4);
    printf("Sum: ");
    printLinkedList(sum2);
    return 0;
}