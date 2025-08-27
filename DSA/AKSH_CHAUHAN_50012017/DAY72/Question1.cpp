#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive function to mirror the tree
Node* mirror(Node* root) {
    if (root == nullptr) return nullptr;
    // Swap left and right
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);

    return root;
}

// Inorder traversal to check result
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    mirror(root);

    cout << "Mirrored tree (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
