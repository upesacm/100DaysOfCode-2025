#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* reverseList(Node* head) {
    Node* previous = nullptr;  
    Node* current = head;      

    while (current != nullptr) {
        Node* nextNode = current->next; 
        current->next = previous;       
        previous = current;            
        current = nextNode;             
    }

    
    return previous;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}


int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
