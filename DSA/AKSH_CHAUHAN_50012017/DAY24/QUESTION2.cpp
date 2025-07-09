#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* deleteNAfterM(Node* head, int m, int n) {
    Node* curr = head;

    while (curr) {
        // Skip m nodes
        for (int i = 1; i < m && curr; i++) {
            curr = curr->next;
        }

        if (!curr) break;

        // Start deleting next n nodes
        Node* temp = curr->next;
        for (int i = 0; i < n && temp; i++) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }

        curr->next = temp;  // Connect skipped node to the rest
        curr = temp;        // Move to next m nodes
    }

    return head;
}
