#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal with counter
int kthSmallest(Node* root, int& k) {
    if (!root) return -1;

    // Search in left subtree
    int left = kthSmallest(root->left, k);
    if (left != -1) return left;

    // Visit current node
    k--;
    if (k == 0) return root->val;

    // Search in right subtree
    return kthSmallest(root->right, k);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->left->right = new Node(2);

    int k = 1;
    cout << k << "th smallest element: " << kthSmallest(root, k) << endl;

    return 0;
}
