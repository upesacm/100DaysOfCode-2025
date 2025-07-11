#include <iostream>
#include <set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* makeUnion(Node* head1, Node* head2) {
    set<int> s;
    Node* temp = head1;
    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp) {
        s.insert(temp->data);
        temp = temp->next;
    }
    Node* head = nullptr, *tail = nullptr;
    for (int val : s) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {9,6,4,2,3,8};
    int arr2[] = {1,2,8,6,2};
    Node* head1 = new Node(arr1[0]);
    Node* curr = head1;
    for (int i = 1; i < 6; i++) {
        curr->next = new Node(arr1[i]);
        curr = curr->next;
    }
    Node* head2 = new Node(arr2[0]);
    curr = head2;
    for (int i = 1; i < 5; i++) {
        curr->next = new Node(arr2[i]);
        curr = curr->next;
    }
    Node* res = makeUnion(head1, head2);
    printList(res);
    return 0;
}
