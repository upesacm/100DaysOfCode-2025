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


Node* deleteNodes(Node* head, int m, int n) {
    Node* current = head;

    while (current) {
        
        for (int i = 1; i < m && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) break;


        Node* temp = current->next;
        for (int i = 0; i < n && temp != nullptr; i++) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete; 
        }

        
        current->next = temp;
        current = temp; 
    }

    return head;
}


void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main() {
    
    Node* head = new Node(9);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next = new Node(1);

    cout << "Original List: ";
    printList(head);

    head = deleteNodes(head, 2, 1);

    cout << "After Deletion (m=2, n=1): ";
    printList(head);

    return 0;
}
