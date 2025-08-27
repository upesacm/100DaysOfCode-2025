#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find middle node
int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

// Helper to insert at end
void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

// Example usage
int main() {
    Node* head = nullptr;
    insert(head, 2);
    insert(head, 4);
    insert(head, 6);
    insert(head, 7);
    insert(head, 5);
    insert(head, 1);

    cout << "Middle element is: " << findMiddle(head) << endl;
    return 0;
}
