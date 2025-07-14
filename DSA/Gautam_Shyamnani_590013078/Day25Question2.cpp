#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* getIntersection(ListNode* head1, ListNode* head2) {
    ListNode* dummy = new ListNode(0); 
    ListNode* tail = dummy;

    while (head1 && head2) {
        if (head1->val == head2->val) {
            tail->next = new ListNode(head1->val); 
            tail = tail->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->val < head2->val) {
            head1 = head1->next;
        }
        else {
            head2 = head2->next;
        }
    }

    return dummy->next;
}
