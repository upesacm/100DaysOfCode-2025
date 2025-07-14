#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* intersectionSortedLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0), *tail = &dummy;
    while (l1 && l2) {
        if (l1->val == l2->val) {
            tail->next = new ListNode(l1->val);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->val < l2->val) {
            l1 = l1->next;
        } else {
            l2 = l2->next;
        }
    }
    return dummy.next;
}

// Example usage
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(6);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    l2->next->next->next = new ListNode(8);

    ListNode* result = intersectionSortedLists(l1, l2);
    printList(result);
    return 0;
}
