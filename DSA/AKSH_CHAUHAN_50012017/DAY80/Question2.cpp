#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Find minimum node (for successor)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (!root->left && !root->right) { // Leaf
            delete root;
            return nullptr;
        } 
        else if (!root->left) { // Only right child
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) { // Only left child
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        else { // Two children
            Node* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 3);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
