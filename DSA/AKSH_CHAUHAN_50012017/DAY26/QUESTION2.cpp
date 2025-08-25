#include <iostream>
#include <set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* makeUnion(Node* head1, Node* head2) {
    set<int> s;
    
    while (head1) {
        s.insert(head1->data);
        head1 = head1->next;
    }
    
    while (head2) {
        s.insert(head2->data);
        head2 = head2->next;
    }

    Node* newHead = NULL, *tail = NULL;
    for (int val : s) {
        Node* newNode = new Node(val);
        if (!newHead) {
            newHead = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return newHead;
}
