#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* swapKthNodes(Node* head, int k) {
    int n = countNodes(head);
    if (k > n) return head;
    if (2 * k - 1 == n) return head; // both nodes are same

    Node* prevX = NULL, *x = head;
    for (int i = 1; i < k; i++) {
        prevX = x;
        x = x->next;
    }

    Node* prevY = NULL, *y = head;
    for (int i = 1; i < n - k + 1; i++) {
        prevY = y;
        y = y->next;
    }

    if (prevX) prevX->next = y;
    if (prevY) prevY->next = x;

    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1) head = y;
    if (k == n) head = x;

    return head;
}
