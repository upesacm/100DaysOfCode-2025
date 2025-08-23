#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    while (head) {
        Node* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

Node* addLists(Node* num1, Node* num2) {
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) { sum += num1->data; num1 = num1->next; }
        if (num2) { sum += num2->data; num2 = num2->next; }

        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    return reverseList(dummy->next);
}
