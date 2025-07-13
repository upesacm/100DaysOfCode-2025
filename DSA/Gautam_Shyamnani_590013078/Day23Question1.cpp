#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int findKthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < k; ++i) {
        if (!fast) return -1; 
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    
    return slow ? slow->data : -1;
}

Node* createList(initializer_list<int> values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : values) {
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }
    return head;
}

int main() {
    Node* list1 = createList({1,2,3,4,5,6,7,8,9});
    cout << "Kth from end (k=2): " << findKthFromEnd(list1, 2) << endl; 

    Node* list2 = createList({10,5,100,5});
    cout << "Kth from end (k=5): " << findKthFromEnd(list2, 5) << endl; 

    return 0;
}
