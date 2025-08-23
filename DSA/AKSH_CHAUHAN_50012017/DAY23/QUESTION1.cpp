#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int kthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (!fast) return -1; // k is more than the length
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow ? slow->data : -1;
}