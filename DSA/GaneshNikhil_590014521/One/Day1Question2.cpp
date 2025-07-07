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

    int FindFrequency(int element){
        if(head == nullptr){
            return -1;
        }
        Node *temp = head;
        int counter = 0;
        while(temp -> next != nullptr){
            if(temp->data == element){
                counter++;
            }
            temp = temp->next;
        }
        return counter;
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
    
    cout<<"Enter the element: ";
    cin >> element;

    if(element){
        int frequencey = list.FindFrequency(element);
        cout << element<<" is repeated "<<frequencey<<" times in linked list"<< endl;
    }
    return 0;
}
