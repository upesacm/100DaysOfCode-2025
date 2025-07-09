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
    void delete_idx(int idx){
        if(head == nullptr || idx <= 0){
            return;
        }
        if(idx == 1){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        int count = 1;
        Node *cur = head;
        Node *prev = nullptr;
        while(count < idx && cur != nullptr){
            prev = cur;
            cur = cur->next;
            count++;
        }
        
         // If index is out of range
        if (cur == nullptr) return;
        prev->next = cur->next;
        delete cur;
        return;
    }
};

int main() {
    LinkedList list;
    int size, value , idx;

    cout << "Enter size of linked list: ";
    cin >> size;

    cout << "Enter " << size << " values:\n";
    for (int i = 0; i < size; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Intial Linked List: ";
    list.printList();
    
    cout<<"Index to delete: ";
    cin>>idx;
    list.delete_idx(idx);
    cout << " linked list after Deletion is:" <<endl;
    list.printList();

    return 0;
}
