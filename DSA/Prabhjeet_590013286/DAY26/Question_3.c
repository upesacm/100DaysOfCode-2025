#include <stdio.h>

struct Node {
    int val;
    struct Node* next;
};

void sortList(struct Node* head) {
    int count0 = 0, count1 = 0, count2 = 0;
    struct Node* temp = head;

    while (temp) {
        if (temp->val == 0) count0++;
        else if (temp->val == 1) count1++;
        else count2++;
        temp = temp->next;
    }

    temp = head;
    while (count0--) { temp->val = 0; temp = temp->next; }
    while (count1--) { temp->val = 1; temp = temp->next; }
    while (count2--) { temp->val = 2; temp = temp->next; }
} //done!
