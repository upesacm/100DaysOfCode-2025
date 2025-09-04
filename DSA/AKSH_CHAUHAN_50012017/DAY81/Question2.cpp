#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper: inorder traversal and linking
void inorder(Node* root, ListNode*& head, ListNode*& tail) {
    if (!root) return;

    inorder(root->left, head, tail);

    ListNode* newNode = new ListNode(root->val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    inorder(root->right, head, tail);
}

ListNode* bstToSortedList(Node* root) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    inorder(root, head, tail);
    return head;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    ListNode* head = bstToSortedList(root);

    cout << "Sorted Linked List: ";
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
