#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) return newNode;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    return head;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main() {
    int n, val;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }
    head = reverseList(head);
    printList(head);
    return 0;
}
