#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Search in BST
bool searchBST(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;
    if (key < root->val) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

// Inorder traversal (for checking tree content)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Example BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int key = 4;
    cout << "Searching " << key << ": " 
         << (searchBST(root, key) ? "Yes" : "No") << endl;

    return 0;
}
