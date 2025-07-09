#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* deleteAtPosition(Node* head, int x) {
    if (!head) return NULL;

    // Delete head if x == 1
    if (x == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    for (int i = 1; i < x - 1 && curr->next; i++) {
        curr = curr->next;
    }

    if (!curr->next) return head; // Invalid x

    Node* toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;

    return head;
}
