#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* reverseDLL(Node* head) {
    Node* temp = nullptr;
    Node* current = head;

    while (current) {
       
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

       
        current = current->prev; 
    }

    if (temp) head = temp->prev;

    return head;
}
