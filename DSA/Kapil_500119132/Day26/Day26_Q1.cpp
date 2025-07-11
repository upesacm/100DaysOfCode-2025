#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* swapKth(Node* head, int k) {
    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }
    if (k > n) return head;
    if (2 * k - 1 == n) return head;
    Node* x_prev = nullptr, *x = head;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
    Node* y_prev = nullptr, *y = head;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }
    if (x_prev) x_prev->next = y;
    if (y_prev) y_prev->next = x;
    Node* temp2 = x->next;
    x->next = y->next;
    y->next = temp2;
    if (k == 1) head = y;
    if (k == n) head = x;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    int k = 1;
    head = swapKth(head, k);
    printList(head);
    return 0;
}
