#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }


    return slow;
}


void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}


int main() {
    
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);

    cout << "Linked List: ";
    printList(head);

    ListNode* middle = findMiddle(head);
    cout << "Middle Node: " << middle->val << endl;

    return 0;
}
