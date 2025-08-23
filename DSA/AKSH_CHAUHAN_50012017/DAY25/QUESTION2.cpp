#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* getIntersection(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (l1 && l2) {
        if (l1->data == l2->data) {
            tail->next = new Node(l1->data);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->data < l2->data) {
            l1 = l1->next;
        } else {
            l2 = l2->next;
        }
    }

    return dummy->next;
}
