#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int checkHeight(Node* root) {
    if (root == nullptr) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(3);

    cout << (isBalanced(root1) ? "Yes" : "No") << endl;

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    cout << (isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}
