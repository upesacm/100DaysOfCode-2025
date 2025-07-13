#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getLength(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

bool swapKthNodes(Node*& head, int k) {
    int length = getLength(head);
    

    if (k > length || k <= 0) return false;
    
 
    if (2 * k - 1 == length) return true;

    
    Node* firstPrev = nullptr;
    Node* first = head;
    for (int i = 1; i < k; ++i) {
        firstPrev = first;
        first = first->next;
    }


    Node* secondPrev = nullptr;
    Node* second = head;
    for (int i = 1; i < length - k + 1; ++i) {
        secondPrev = second;
        second = second->next;
    }

    if (firstPrev) firstPrev->next = second;
    else head = second;

    if (secondPrev) secondPrev->next = first;
    else head = first;

    Node* temp = first->next;
    first->next = second->next;
    second->next = temp;

    return true;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int k = 1;

    cout << "Before swapping:\n";
    printList(head);

    if (swapKthNodes(head, k))
        cout << "After swapping:\n";
    else
        cout << "Invalid k. No swap performed.\n";
    
    printList(head);
}
