#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* deleteAtPosition(Node* head, int pos) {
    if (!head) return head;
    Node* curr = head;
    int count = 1;
    while (curr && count < pos) {
        curr = curr->next;
        count++;
    }
    if (!curr) return head;
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    delete curr;
    return head;
}
