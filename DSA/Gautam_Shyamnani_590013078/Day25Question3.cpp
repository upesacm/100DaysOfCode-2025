#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); 
    ListNode* tail = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; 
        tail->next = new ListNode(sum % 10); 
        tail = tail->next;
    }

    return dummy->next;
}
