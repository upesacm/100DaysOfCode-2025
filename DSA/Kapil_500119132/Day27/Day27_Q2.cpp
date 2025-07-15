#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* reverseDLL(Node* head) {
    Node* temp = nullptr;
    Node* curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
    return head;
}
