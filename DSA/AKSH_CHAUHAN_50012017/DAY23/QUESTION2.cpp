#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* dup = current->next;
            current->next = current->next->next;
            delete dup;
        } else {
            current = current->next;
        }
    }

    return head;
}