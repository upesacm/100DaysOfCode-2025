#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* sort012(Node* head) {
    Node *zeroHead = new Node(0), *oneHead = new Node(0), *twoHead = new Node(0);
    Node *zero = zeroHead, *one = oneHead, *two = twoHead;

    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // Connect three lists
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    Node* sortedHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return sortedHead;
}
