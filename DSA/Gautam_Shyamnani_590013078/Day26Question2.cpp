#include <iostream>
#include <set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* makeUnion(Node* head1, Node* head2) {
    set<int> values;

    
    Node* temp = head1;
    while (temp) {
        values.insert(temp->data);
        temp = temp->next;
    }


    temp = head2;
    while (temp) {
        values.insert(temp->data);
        temp = temp->next;
    }


    Node* newHead = nullptr;
    Node* tail = nullptr;
    for (int val : values) {
        Node* newNode = new Node(val);
        if (!newHead) {
            newHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}


int main() {

    Node* L1 = new Node(9);
    L1->next = new Node(6);
    L1->next->next = new Node(4);
    L1->next->next->next = new Node(2);
    L1->next->next->next->next = new Node(3);
    L1->next->next->next->next->next = new Node(8);


    Node* L2 = new Node(1);
    L2->next = new Node(2);
    L2->next->next = new Node(8);
    L2->next->next->next = new Node(6);
    L2->next->next->next->next = new Node(2);

    Node* unionList = makeUnion(L1, L2);
    cout << "Union Linked List:\n";
    printList(unionList);
}
