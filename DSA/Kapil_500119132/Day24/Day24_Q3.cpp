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

Node* deleteAtPosition(Node* head, int x) {
    if (x == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    for (int i = 1; i < x - 1 && curr; i++)
        curr = curr->next;
    if (!curr || !curr->next)
        return head;
    Node* toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n, val, pos;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }
    cin >> pos;
    head = deleteAtPosition(head, pos);
    printList(head);
    return 0;
}
