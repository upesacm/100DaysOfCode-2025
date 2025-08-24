#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int countFrequency(Node* head, int key) {
    int count = 0;
    while (head != nullptr) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

int main() {
    Node* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);
    insert(head, 1);

    int key = 1;
    cout << "Frequency of " << key << " is: " << countFrequency(head, key) << endl;
    return 0;
}
