#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    ListNode* secondHalf = reverse(slow->next);

    
    ListNode* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
