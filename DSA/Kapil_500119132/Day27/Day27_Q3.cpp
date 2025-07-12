#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* removeEveryKthNode(Node* head, int k) {
    if (k == 0 || !head) return head;
    Node* curr = head;
    Node* prev = nullptr;
    int count = 1;
    while (curr) {
        if (count % k == 0) {
            Node* temp = curr;
            if (prev) prev->next = curr->next;
            else head = curr->next;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
        count++;
    }
    return head;
}
