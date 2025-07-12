#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* deleteNode(Node* head, int x) {

    if (!head) return nullptr;

    Node* temp = head;


    if (x == 1) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return head;
    }

    for (int i = 1; temp && i < x; i++) {
        temp = temp->next;
    }

   
    if (!temp) return head;

   
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;

    delete temp;
    return head;
}
