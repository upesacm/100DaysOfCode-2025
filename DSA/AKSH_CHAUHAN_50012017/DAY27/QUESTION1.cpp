#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

Node* deleteNode(Node* head, int pos) {
    if (!head) return NULL;

    Node* curr = head;

    // Traverse to the position
    for (int i = 1; curr && i < pos; i++) {
        curr = curr->next;
    }

    if (!curr) return head;

    // If deleting head
    if (!curr->prev) {
        head = curr->next;
        if (head) head->prev = NULL;
    } else {
        curr->prev->next = curr->next;
        if (curr->next)
            curr->next->prev = curr->prev;
    }

    delete curr;
    return head;
}
