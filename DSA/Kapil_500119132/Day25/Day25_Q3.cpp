#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
    ListNode dummy(0), *tail = &dummy;
    int carry = 0;
    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) {
            sum += num1->val;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->val;
            num2 = num2->next;
        }
        carry = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
    }
    while (dummy.next && dummy.next->val == 0 && dummy.next->next) {
        ListNode* temp = dummy.next;
        dummy.next = dummy.next->next;
        delete temp;
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
    ListNode* num1 = new ListNode(0);
    num1->next = new ListNode(0);
    num1->next->next = new ListNode(6);
    num1->next->next->next = new ListNode(3);

    ListNode* num2 = new ListNode(0);
    num2->next = new ListNode(7);

    ListNode* result = addTwoNumbers(num1, num2);
    printList(result);
    return 0;
}
