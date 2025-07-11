#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Helper to reverse a list
Node* reverse(Node* head) {
    Node* prev = NULL;
    while (head) {
        Node* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // Find middle (slow will stop at middle)
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse second half
    Node* secondHalf = reverse(slow);
    Node* firstHalf = head;

    // Compare both halves
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
