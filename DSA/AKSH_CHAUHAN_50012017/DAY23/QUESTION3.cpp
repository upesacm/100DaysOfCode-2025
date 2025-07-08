#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* deleteMiddle(Node* head) {
    if (!head || !head->next) return NULL;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Use slow-fast pointer method to find the middle
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete middle node
    prev->next = slow->next;
    delete slow;

    return head;
}