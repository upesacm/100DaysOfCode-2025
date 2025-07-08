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

   int kth_element(int k) {
    if (head == nullptr || k < 0)
        return -1;

    Node* p = head;
    Node* q = head;

    // Move q ahead by k nodes
    for (int i = 0; i < k; i++) {
        if (q == nullptr) return -1; // k > length of list
        q = q->next;
    }

    if (q == nullptr) return -1; // k == length of list (0-based from end)

    while (q->next != nullptr) {
        q = q->next;
        p = p->next;
    }

    return p->data;
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
    
    cout << "Enter the kth index from last: ";
    cin >> element;
    int kth = list.kth_element(element);
    cout << "the "<< element<<"th element from last is "<<kth<< endl;

    return 0;
}
