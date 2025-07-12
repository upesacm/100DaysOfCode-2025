#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* sortList(Node* head) {
    if (!head || !head->next) return head;

    Node *zeroHead = new Node(-1), *oneHead = new Node(-1), *twoHead = new Node(-1);
    Node *zero = zeroHead, *one = oneHead, *two = twoHead;

    Node* current = head;
    while (current) {
        if (current->data == 0) {
            zero->next = current;
            zero = zero->next;
        } else if (current->data == 1) {
            one->next = current;
            one = one->next;
        } else {
            two->next = current;
            two = two->next;
        }
        current = current->next;
    }


    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    
    Node* sortedHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return sortedHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}


Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}


int main() {
    int arr[] = {1, 2, 2, 1, 2, 0, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, n);

    cout << "Original List:\n";
    printList(head);

    head = sortList(head);

    cout << "\nSorted List:\n";
    printList(head);

    return 0;
}
