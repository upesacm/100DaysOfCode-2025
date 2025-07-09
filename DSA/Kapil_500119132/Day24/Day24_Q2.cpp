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

Node* deleteNafterM(Node* head, int m, int n) {
    Node* curr = head;
    while (curr) {
        for (int i = 1; i < m && curr; i++)
            curr = curr->next;
        if (!curr) break;
        Node* temp = curr->next;
        for (int i = 0; i < n && temp; i++) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n, val, m, deln;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }
    cin >> m >> deln;
    head = deleteNafterM(head, m, deln);
    printList(head);
    return 0;
}
