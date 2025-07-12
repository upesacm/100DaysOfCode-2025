#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* removeKthNode(Node* head, int k) {

    if (!head || k == 0) return head;

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while (current) {
        if (count % k == 0) {
          
            if (prev) prev->next = current->next;
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }

    return head;
}
