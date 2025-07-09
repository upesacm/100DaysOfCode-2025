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

    void reverse_lst(){
        if(head == nullptr){
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;


        while(current != nullptr){
            next = current->next; // Save next node
            current->next = prev; // Reverse the current node
            prev = current; // Move prev ahead
            current = next; // Move current ahead

        }
        head = prev;  // Update head to the new front
    }
};

int main() {
    LinkedList list;
    int size, value;

    cout << "Enter size of linked list: ";
    cin >> size;

    cout << "Enter " << size << " values:\n";
    for (int i = 0; i < size; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Intial Linked List: ";
    list.printList();

    list.reverse_lst();
    cout << "Reversed  linked list is:" << endl;
    list.printList();

    return 0;
}
