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


Node* deleteMiddle(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

   
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    
    prev->next = slow->next; 

    delete slow; 
    return head;
}


void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next) cout << "->";
        current = current->next;
    }
    cout << endl;
}


Node* createList(const initializer_list<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int value : values) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Example usage
int main() {
    Node* head1 = createList({1, 2, 3, 4, 5});
    head1 = deleteMiddle(head1);
    printList(head1);

    Node* head2 = createList({2, 4, 6, 7, 5, 1});
    head2 = deleteMiddle(head2);
    printList(head2); 
    Node* head3 = createList({10});
    head3 = deleteMiddle(head3);
    printList(head3); 

    return 0;
}
