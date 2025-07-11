#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* sortList(Node* head) {
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);
    Node* zero = zeroD, *one = oneD, *two = twoD;
    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    zero->next = oneD->next ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = nullptr;
    head = zeroD->next;
    delete zeroD; delete oneD; delete twoD;
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
    int arr[] = {1,2,2,1,2,0,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    head = sortList(head);
    printList(head);
    return 0;
}
