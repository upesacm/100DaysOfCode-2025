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
    LinkedList() : head(nullptr) {}

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

    int deleteMid() {
        if (head == nullptr) return -1;

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        int midValue = slow->data;

        // Handle single element case
        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = slow->next;
        }

        delete slow;
        return midValue;
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

    cout << "Original Linked List: ";
    list.printList();

    int mid = list.deleteMid();
    if (mid != -1)
        cout << "Deleted middle value: " << mid << endl;
    else
        cout << "List was empty, nothing deleted." << endl;

    cout << "Updated Linked List: ";
    list.printList();

    return 0;
}
