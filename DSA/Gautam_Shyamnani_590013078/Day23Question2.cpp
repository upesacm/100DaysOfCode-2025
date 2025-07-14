#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
        
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp; 
        } else {
            current = current->next; 
        }
    }

    return head;
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


void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = createList({2, 2, 4, 5});
    list1 = removeDuplicates(list1);
    printList(list1); 

    Node* list2 = createList({2, 2, 2, 2, 2});
    list2 = removeDuplicates(list2);
    printList(list2); 

    return 0;
}
