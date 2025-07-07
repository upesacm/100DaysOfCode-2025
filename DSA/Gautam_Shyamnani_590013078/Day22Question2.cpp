#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


int countOccurrences(ListNode* head, int key) {
    int count = 0;
    ListNode* current = head;

    while (current != nullptr) {
        if (current->val == key) {
            count++;
        }
        current = current->next;
    }

    return count;
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
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(1);

    int key = 1;

    cout << "Linked List: ";
    printList(head);

    int result = countOccurrences(head, key);
    cout << "Occurrences of " << key << ": " << result << endl;

    return 0;
}
