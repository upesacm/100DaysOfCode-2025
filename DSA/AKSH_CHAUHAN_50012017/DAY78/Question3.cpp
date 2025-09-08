#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Find minimum value in BST
int findMin(Node* root) {
    if (root == nullptr) throw runtime_error("Tree is empty");
    while (root->left != nullptr) root = root->left;
    return root->val;
}

// Find maximum value in BST
int findMax(Node* root) {
    if (root == nullptr) throw runtime_error("Tree is empty");
    while (root->right != nullptr) root = root->right;
    return root->val;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << "Min = " << findMin(root) << ", Max = " << findMax(root) << endl;

    return 0;
}
