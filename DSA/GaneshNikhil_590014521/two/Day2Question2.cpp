#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

void remove_duplicates() {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;  // Free memory
        } else {
            current = current->next;
        }
    }
}

};

int main() {
    LinkedList list;
    int size, value , element;

    cout << "Enter size of linked list: ";
    cin >> size;

    cout << "Enter " << size << " values:\n";
    for (int i = 0; i < size; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Linked List: ";
    list.printList();
    
    list.remove_duplicates();
    cout << "Linked List after removing duplicates: ";
    list.printList();

    return 0;
}
