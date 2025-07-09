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
    void delete_n_after_m(int m, int n) {
        if (head == nullptr || n == 0)
            return;

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            // Step 1: Skip m nodes
            for (int i = 0; i < m && current != nullptr; i++) {
                prev = current;
                current = current->next;
            }

            // Step 2: Delete n nodes after m skipped
            for (int i = 0; i < n && current != nullptr; i++) {
                Node* to_delete = current;
                current = current->next;
                delete to_delete;
            }

            // Connect previous segment to the node after deletion
            if (prev != nullptr) {
                prev->next = current;
            } else {
                head = current;  // Edge case if m = 0 and deletion is from start
            }
        }
    }
};

int main() {
    LinkedList list;
    int size, value , m , n;

    cout << "Enter size of linked list: ";
    cin >> size;

    cout << "Enter " << size << " values:\n";
    for (int i = 0; i < size; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Intial Linked List: ";
    list.printList();
    
    cout<<"Enter n and m: ";
    cin>> n >> m;
    list.delete_n_after_m(n , m);
    cout << " linked list after n and m is:" << endl;
    list.printList();

    return 0;
}
