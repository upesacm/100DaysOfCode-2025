#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void sortList(struct Node* head) {
    int count[3] = {0, 0, 0};
    struct Node* ptr = head;

    while (ptr) {
        count[ptr->data]++;
        ptr = ptr->next;
    }

    ptr = head;
    int i = 0;
    while (ptr) {
        if (count[i] == 0)
            ++i;
        else {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}
