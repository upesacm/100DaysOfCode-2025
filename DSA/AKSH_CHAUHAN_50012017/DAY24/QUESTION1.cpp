#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while (curr) {
        Node* nextNode = curr->next; // store next
        curr->next = prev;           // reverse current node's pointer
        prev = curr;                 // move prev forward
        curr = nextNode;             // move curr forward
    }

    return prev; // new head
}
