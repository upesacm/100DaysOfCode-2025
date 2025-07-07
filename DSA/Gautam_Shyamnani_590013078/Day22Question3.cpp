#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    cout << endl; 
}


int main() {
    
    ListNode* head = new ListNode(49);
    head->next = new ListNode(10);
    head->next->next = new ListNode(30);

    cout << "Linked List: ";
    printLinkedList(head);

    return 0;
}
