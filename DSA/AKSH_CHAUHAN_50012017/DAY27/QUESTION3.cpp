#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* removeEveryKth(Node* head, int k) {
    if (k <= 0 || !head) return head;
    if (k == 1) {
        // delete all nodes
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return NULL;
    }

    Node* curr = head;
    int count = 1;

    while (curr && curr->next) {
        if ((count + 1) % k == 0) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            count++;
        } else {
            curr = curr->next;
            count++;
        }
    }

    return head;
}
