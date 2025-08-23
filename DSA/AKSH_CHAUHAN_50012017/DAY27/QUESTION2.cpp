#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

Node* reverseDoublyList(Node* head) {
    if (!head) return NULL;

    Node* curr = head;
    Node* temp = NULL;

    // Swap next and prev for each node
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // New head is last processed node
    if (temp)
        head = temp->prev;

    return head;
}
